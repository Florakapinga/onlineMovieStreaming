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
    void streamMovie(int index) const
    {
        if (index >= 0 && index < movies.size())
        {
            std::cout << "Streaming: " << movies[index].getTitle() << "\n";
            std::cout << "Enjoy your movie!\n";
        }
        else
        {
            std::cout << "Invalid movie index!\n";
        }
    }
    size_t getMoviesCount() const
    { // Added method to get the count of movies
        return movies.size();
    }
};
int main()
{
    StreamingService service;

    int choice;

    do
    {
        std::cout << "\n=== Online Movie Streaming Service ===\n";
        std::cout << "1. Add Movie\n";
        std::cout << "2. Display Movies\n";
        std::cout << "3. Stream Movie\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            std::string title, genre;
            double duration;

            std::cin.ignore(); // Clear input buffer
            std::cout << "Enter movie title: ";
            getline(std::cin, title);

            std::cout << "Enter movie genre: ";
            getline(std::cin, genre);

            std::cout << "Enter movie duration (in minutes): ";
            std::cin >> duration;

            service.addMovie(Movie(title, genre, duration));
            break;
        }
        case 2:
            service.displayMovies();
            break;
        case 3:
        {
            int index;
            service.displayMovies();

            if (service.getMoviesCount() == 0)
            {          // Check if there are any movies
                break; // No movies to stream
            }

            std::cout << "\nEnter the movie index to stream: ";
            std::cin >> index;

            service.streamMovie(index - 1); // Adjusting for zero-based index
            break;
        }
        case 4:
            std::cout << "Exiting the system.\n";
            break;
        default:
            std::cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
