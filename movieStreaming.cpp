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
    void displayInfo() const
    {
        std::cout << "Title: " << title << "\n"
                  << "Genre: " << genre << "\n"
                  << "Duration: " << duration << " minutes\n";
    }

    std::string getTitle() const
    {
        return title;
    }
};
class StreamingService
{
private:
    std::vector<Movie> movies;

public:
    void addMovie(const Movie &movie)
    {
        movies.push_back(movie);
        std::cout << "Movie added successfully!\n";
    }
    void displayMovies() const
    {
        if (movies.empty())
        {
            std::cout << "No movies available.\n";
            return;
        }

        std::cout << "\nAvailable Movies:\n";
        for (size_t i = 0; i < movies.size(); ++i)
        {
            std::cout << i + 1 << ". ";
            movies[i].displayInfo();
            std::cout << "\n";
        }
    }
