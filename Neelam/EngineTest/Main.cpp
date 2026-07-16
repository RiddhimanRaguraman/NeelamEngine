#include "Entity.h"
#include "Transform.h"

int main()
{
	Test::RunTests();

	// Release the engine's file-scope arrays here, at a point we control.
	// This has to happen before the memory tracker's exit report, and in a
	// deterministic order (entities first, then the transforms they index into)
	// -- static destruction order across translation units is unspecified.
	Neelam::GameEntity::shutdown();
	Neelam::Transform::shutdown();
}
