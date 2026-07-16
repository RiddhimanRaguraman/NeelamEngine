#include "_UnitTestConfiguration.h"
#include "Entity.h"
#include "Transform.h"

#include <ctime>

using namespace Neelam;

//---------------------------------------------------------------------------
// Entity create/remove stress test.
//
// Ported from the Primal engine_test. Two deliberate changes:
//   1. The interactive "do { ... } while (getchar() != 'q')" loop is gone --
//      a unit test can't block waiting on input.
//   2. assert(...) became CHECK(...) so failures are reported by the framework
//      instead of hard-aborting the whole test run.
//---------------------------------------------------------------------------

namespace
{
	constexpr u32 num_iterations{ 10000 };

	// File scope so TEST_TEARDOWN can reach them -- teardown is a separate
	// function and cannot see run()'s locals.
	Util::vector<GameEntity::Entity> entities;

	u32 added{ 0 };
	u32 removed{ 0 };
}

TEST_WITH_TEARDOWN(EngineEntityStress, TestConfig::NONE)
{
#if EngineEntityStress

	srand((u32)time(nullptr));

	for (u32 iteration{ 0 }; iteration < num_iterations; ++iteration)
	{
		// ---- create a random batch ----
		{
			u32 count{ (u32)rand() % 20 };
			if (entities.empty()) count = 1000;

			Transform::init_info    transform_info{};
			GameEntity::entity_info entity_info{ &transform_info };

			while (count > 0)
			{
				++added;

				const GameEntity::Entity entity{ GameEntity::Create_Game_Entity(entity_info) };
				CHECK(entity.is_valid());
				CHECK(Id::is_valid(entity.get_id()));

				entities.push_back(entity);
				CHECK(GameEntity::is_alive(entity));

				--count;
			}
		}

		// ---- remove a random batch ----
		if (entities.size() >= 1000)
		{
			u32 count{ (u32)rand() % 20 };

			while (count > 0)
			{
				const u32 index{ (u32)rand() % (u32)entities.size() };
				const GameEntity::Entity entity{ entities[index] };
				CHECK(entity.is_valid());
				CHECK(Id::is_valid(entity.get_id()));

				GameEntity::Remove_Game_Entity(entity);
				entities.erase(entities.begin() + index);
				CHECK(!GameEntity::is_alive(entity));
				++removed;

				--count;
			}
		}
	}

	Trace::out("Entities Created: %d\n", added);
	Trace::out("Entities Deleted: %d\n", removed);

#endif
} TEST_END

TEST_TEARDOWN(EngineEntityStress)
{
#if EngineEntityStress

	// Always runs -- even if a CHECK above aborted the test -- so the engine is
	// never left holding live entities.
	for (auto& e : entities)
	{
		if (e.is_valid() && GameEntity::is_alive(e))
		{
			GameEntity::Remove_Game_Entity(e);
		}
	}
	// release this vector's block too, so nothing is left allocated at exit
	entities.purge();

#endif
}

// ---  End of File ---
