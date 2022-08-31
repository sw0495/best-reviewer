// Movie.hh
#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <memory>

class MovieType;
class Movie {
public:
  static const int CHILDRENS   = 2;
  static const int REGULAR     = 0;
  static const int NEW_RELEASE = 1;
  static const int BESTSELLER = 3;
  static const int UNKNOWN = 100;

  Movie( const std::string& title, int priceCode = REGULAR );

  int getPriceCode() const;
  void setPriceCode( int arg );
  std::string getTitle() const;
  void setTitle(std::string);
  double payAmount(int);

private:
  std::string movieTitle;
  int moviePriceCode;

  std::shared_ptr<MovieType> m_type;
  int getType();
  void setType(int);
};

#endif // MOVIE_H
