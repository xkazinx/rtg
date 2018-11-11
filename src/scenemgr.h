#include "globals.h"

class SceneMgr : public Drawable {
public:
    SceneMgr();
    ~SceneMgr();

    using ID = SceneID;
    static constexpr ID kDefaultID = ID::Game;

private:
    ID _id;
    array<unique_ptr<Scene>, (szt)ID::Max> _list;

public:
    // Derives to current scene
    void HandleEvents(Event & event);
    void Tick();

    auto & GetID() { return _id; }
    auto & GetID() const { return _id; }

    auto & GetList() { return _list; }
    auto & GetList() const { return _list; }

    Scene * Get(ID id) { return _list[(szt)id].get(); }
    Scene * Get() { return Get(_id); }

    Scene * Get(ID id) const { return _list[(szt)id].get(); }
    Scene * Get() const { return Get(_id); }

    auto & At(ID id) { return _list[(szt)id]; }
    auto & At() { return At(_id); }

    void Set(ID id);

    void draw(RenderTarget& target, RenderStates states) const override;
};