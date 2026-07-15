#include "Entity.h"

// Engine integration test sandbox. Framework.h is force-included by the build,
// and NeelamEngine (+ Math/File/AnimTime) is linked in. Add your tests here.
int main()
{
    // Referencing an exported engine symbol confirms EngineTest links NeelamEngine.
    auto* create = &Neelam::GameEntity::Create_Game_Entity;
    (void)create;
    return 0;
}
