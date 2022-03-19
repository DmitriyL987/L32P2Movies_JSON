#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>


struct Description{
    std::string age_category ="";
    std::string release ="";
    std::string genre ="";
    std::string starring ="";
    std::string running_time ="";
    std::string country ="";
    std::string production_companies ="";
    std::string screenwriter ="";
    std::string directed_by ="";
    std::string produced_by ="";
    std::string cinematography ="";
    std::string music_by ="";
    std::string edited_by ="";
    std::string language ="";
    std::string Based_on = "";
    std::map <std::string, std::string> mainRoles;
};

struct Movie{
    std::string film_title ="";
    Description description;
};

