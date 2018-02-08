#pragma once

#include <array>
#include <optional>
#include <unordered_map>
#include "optional_ref.hpp"



namespace elona
{


struct item_data
{
    int id;
    int image;
    int value;
    int weight;
    int dice_x;
    int dice_y;
    int hit_bonus;
    int damage_bonus;
    int pv;
    int dv;
    int material;
    int chargelevel;
    std::string infilterref;
    std::array<std::string, 4> description_jp;
    std::string description_en;
    int dbspec2;
    int dbspec3;
    int dbspec4;
    int dbspec7;
    int dbspec8;
    int dbspec10;
    int dbspec11;
    int dbspec18;
    int dbspec19;
    int dbspec20;
    int level;
    int fltselect;
    int category;
    int subcategory;
    int rarity;
    int coefficient;
};



class item_db
{
public:
    struct iterator
    {
        iterator(const std::unordered_map<int, item_data>::const_iterator& itr)
            : itr(itr)
        {
        }

        const item_data& operator*() const
        {
            return itr->second;
        }

        void operator++()
        {
            ++itr;
        }

        bool operator!=(const iterator& other) const
        {
            return itr != other.itr;
        }

    private:
        std::unordered_map<int, item_data>::const_iterator itr;
    };


    item_db();


    optional_ref<item_data> operator[](int id) const;


    iterator begin() const
    {
        return iterator{std::begin(storage)};
    }

    iterator end() const
    {
        return iterator{std::end(storage)};
    }


private:
    std::unordered_map<int, item_data> storage;
};



inline item_db the_item_db;


} // namespace elona