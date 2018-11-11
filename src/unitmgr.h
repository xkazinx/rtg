#include "globals.h"

class UnitMgr 
{
public:
    using Id = UnitId;

    UnitMgr() : _create_id(0) {}
    ~UnitMgr();

private:
    Id _create_id;
    vector<unique_ptr<Unit>> _list;
    vector<Unit*> _selected_list;

public:
    auto & GetList() { return _list; }
    auto & GetList() const { return _list; }

    auto & GetSelectedList() { return _selected_list; }
    auto & GetSelectedList() const { return _selected_list; }
    
    void Add(unique_ptr<Unit> && unit);

    // Moves selected units to point
    void Move(const Vector2f & pos);

    template<typename Func>
    auto FindIf(Func func)
    {
        auto it = std::find_if(GetList().begin(), GetList().end(), func);
        return it != _list.end() ? it->get() : nullptr;
    }

    Unit * FindById(const Id & id);

    /**
     * Returns a vector of Unit*
     * auto results = FindAllIf([&](auto & unit) { unit->Is(id); });
     */ 
    template<typename Func>
    auto FindAllIf(Func func) 
    {
        vector<Unit*> res;

        for(auto & it : GetList()) 
        {
            if (!func(it.get())) 
                continue;
                
            res.push_back(it.get());
        }

        return res;
    }

    void Select(const FloatRect & area);

    RectangleShape test;
};