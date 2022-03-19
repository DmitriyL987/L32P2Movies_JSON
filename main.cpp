#include "Movie.hpp"

#include "nlohmann/json.hpp"

void shortDescript(std::vector<Movie> &movie, std::string& query)
{
    std::cout << "search..." << std::endl;
    double conc = 0;
    int count = 0;
    std::vector<std::string> found;
    for(auto el : movie){
        for (auto key : el.description.mainRoles){
            std::string source(key.first);
            int index = -1;
            index = source.find(query);
            if(index >= 0){
                ++count;
                int ends = source.find(" ", index);
                std::string subs = source.substr(index, ends);
                conc = query.length()*100/subs.length();
                if(conc >= 100) conc = 100;
                found.emplace_back(el.film_title);
                found.emplace_back(key.first);
                found.emplace_back(key.second);
            }
        }
    }
    std::cout << "Found " << count << " results. Coincidence " <<  conc << "%" << std::endl;
    for (int i = 0; i < found.size(); i += 3){
        std::cout << "Title: " << found[i] << std::endl;
        std::cout << "Actor: " << found[i+1] << "\tas " << found[i+2] << std::endl;
    }
}

int main() {
    nlohmann::json j;
    std::ifstream file("C:\\Users\\LDm\\AppData\\Roaming\\JetBrains\\CLion2021.2\\scratches\\playlist.json");
    if (!file.is_open()) {
        std::cerr << "could not open the file" << std::endl;
        return 0;
    }
    std::cout << "Enter the actor's name or surname: " << std::endl;
    std::string query;
    getline(std::cin, query);
    file >> j;
    std::cout << j.size() << std::endl;
    std::vector<Movie> mov(j.size());
    int i = 0;
    for (nlohmann::json::iterator it = j.begin(); it != j.end(); ++it) {
        std::cout << "Iteration " << i << std::endl;
        mov[i].film_title = it.key();
        mov[i].description.screenwriter = (*it)["Written by"];
        mov[i].description.genre = (*it)["Genre"];
        mov[i].description.cinematography = (*it)["Cinematography"];
        mov[i].description.country = (*it)["Countries"];
        mov[i].description.directed_by = (*it)["Directed by"];
        mov[i].description.edited_by = (*it)["Edited by"];
        mov[i].description.produced_by = (*it)["Produced by"];
        mov[i].description.music_by = (*it)["Music by"];
        mov[i].description.production_companies = (*it)["Production Company"];
        mov[i].description.age_category = (*it)["Age category"];
        mov[i].description.release =  (*it)["Release date"];
        mov[i].description.running_time =  (*it)["Running time"];
        mov[i].description.language = (*it)["Language"];
        mov[i].description.Based_on = (*it)["Based on"];
        mov[i].description.starring = (*it)["Starring"];
        mov[i].description.mainRoles = (*it)["Actors and roles"].get<std::map <std::string, std::string>>();
        ++i;
    }
    shortDescript(mov, query);
    file.close();
}
