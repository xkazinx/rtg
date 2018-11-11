#include "globals.h"
#include "unitmgr.h"
#include "unit.h"
#include "scenemgr.h"
#include "scene.h"

namespace g
{
    unique_ptr<UnitMgr> unit_mgr;
    unique_ptr<SceneMgr> scene_mgr;

    /**
     * Reason to use methods is to specify the order
     * of construction and deconstruction of every instance
     */
    void Initialize()
    {
        unit_mgr = make_unique<UnitMgr>();
        scene_mgr = make_unique<SceneMgr>();
    }
    
    void Deinitialize()
    {
        unit_mgr.reset();
        scene_mgr.reset();
    }
}