#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
class Movie
{
private:
    std::string title;
    std::string genre;
    double duration; // Duration in minutes

public:
    Movie(std::string t, std::string g, double d)
        : title(t), genre(g), duration(d) {}
