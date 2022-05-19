#include <cmath>                                                      // abs(), pow()
#include <compare>                                                    // weak_ordering
#include <iomanip>                                                    // quoted()
#include <iostream>
#include <string>
#include <type_traits>                                                // is_floating_point_v, common_type_t
#include <utility>                                                    // move()

#include "Book.hpp"



/*******************************************************************************
**  Implementation of non-member private types, objects, and functions
*******************************************************************************/
namespace    // unnamed, anonymous namespace
{
  // Avoid direct equality comparisons on floating point numbers. Two values are equal if they are "close enough", which is
  // represented by Epsilon.  Usually, this is a pretty small number, but since we are dealing with money (only two, maybe three
  // decimal places) we can be a bit more tolerant.  Two floating point values are considered equal if they are within EPSILON of
  // each other.
  template< typename T,  typename U >   requires std::is_floating_point_v<std::common_type_t<T, U> >
  constexpr bool floating_point_is_equal( T const lhs,  U const rhs,  double const EPSILON = 1e-4 ) noexcept
  {
    ///////////////////////// TO-DO (1) //////////////////////////////
      ///  Write the lines of code that compare two floating point numbers.  Return true when the left hand side (lhs) and the right
      ///  hand side (rhs) are within Epsilon, and false otherwise.
      ///
      ///  See: "Floating point equality" in https://www.learncpp.com/cpp-tutorial/relational-operators-and-floating-point-comparisons/
      ///
      ///  Hint:  Avoid writing code that looks like this:
      ///           if( some expression that is true ) return the constant "true"
      ///           else                               return the constant "false"
      ///         for example, avoid:
      ///           if (a < b) return true;
      ///           else       return false;
      ///         do this instead:
      ///           return a < b;

    /////////////////////// END-TO-DO (1) ////////////////////////////
  }
}    // unnamed, anonymous namespace







/*******************************************************************************
**  Constructors, assignments, and destructor
*******************************************************************************/

// Default and Conversion Constructor
Book::Book( std::string title,  std::string author,  std::string isbn,  double price )
///////////////////////// TO-DO (2) //////////////////////////////

/////////////////////// END-TO-DO (2) ////////////////////////////




// Copy constructor
Book::Book( Book const & other )
///////////////////////// TO-DO (3) //////////////////////////////

/////////////////////// END-TO-DO (3) ////////////////////////////




// Move constructor
Book::Book( Book && other ) noexcept
///////////////////////// TO-DO (4) //////////////////////////////

/////////////////////// END-TO-DO (4) ////////////////////////////




// Copy Assignment Operator
Book & Book::operator=( Book const & rhs ) &
///////////////////////// TO-DO (5) //////////////////////////////

/////////////////////// END-TO-DO (5) ////////////////////////////




// Move Assignment Operator
Book & Book::operator=( Book && rhs ) & noexcept
///////////////////////// TO-DO (6) //////////////////////////////

/////////////////////// END-TO-DO (6) ////////////////////////////



// Destructor
Book::~Book() noexcept
///////////////////////// TO-DO (7) //////////////////////////////

/////////////////////// END-TO-DO (7) ////////////////////////////








/*******************************************************************************
**  Accessors
*******************************************************************************/

// isbn() const
std::string const & Book::isbn() const &
{
  ///////////////////////// TO-DO (8) //////////////////////////////

  /////////////////////// END-TO-DO (8) ////////////////////////////
}




// title() const
std::string const & Book::title() const &
{
  ///////////////////////// TO-DO (9) //////////////////////////////

  /////////////////////// END-TO-DO (9) ////////////////////////////
}




// author() const
std::string const & Book::author() const &
{
  ///////////////////////// TO-DO (10) //////////////////////////////

  /////////////////////// END-TO-DO (10) ////////////////////////////
}



// price() const
double Book::price() const &
{
  ///////////////////////// TO-DO (11) //////////////////////////////

  /////////////////////// END-TO-DO (11) ////////////////////////////
}




// isbn()
std::string Book::isbn() &&
{
  ///////////////////////// TO-DO (12) //////////////////////////////

  /////////////////////// END-TO-DO (12) ////////////////////////////
}




// title()
std::string Book::title() &&
{
  ///////////////////////// TO-DO (13) //////////////////////////////

  /////////////////////// END-TO-DO (13) ////////////////////////////
}




// author()
std::string Book::author() &&
{
  ///////////////////////// TO-DO (14) //////////////////////////////

  /////////////////////// END-TO-DO (14) ////////////////////////////
}








/*******************************************************************************
**  Modifiers
*******************************************************************************/

// isbn()
Book & Book::isbn( std::string newIsbn ) &
{
  ///////////////////////// TO-DO (15) //////////////////////////////

  /////////////////////// END-TO-DO (15) ////////////////////////////
}




// title()
Book & Book::title( std::string newTitle ) &
{
  ///////////////////////// TO-DO (16) //////////////////////////////

  /////////////////////// END-TO-DO (16) ////////////////////////////
}




// author()
Book & Book::author( std::string newAuthor ) &
{
  ///////////////////////// TO-DO (17) //////////////////////////////

  /////////////////////// END-TO-DO (17) ////////////////////////////
}




// price()
Book & Book::price( double newPrice ) &
{
  ///////////////////////// TO-DO (18) //////////////////////////////

  /////////////////////// END-TO-DO (18) ////////////////////////////
}








/*******************************************************************************
**  Relational Operators
*******************************************************************************/

// operator<=>
std::weak_ordering Book::operator<=>( const Book & rhs ) const noexcept
{
  // Design decision:  A very simple and convenient defaulted 3-way comparison operator
  //                         auto operator<=>( const Book & ) const = default;
  //                   in the class definition (header file) would get very close to what is needed and would allow both the <=> and
  //                   the == operators defined here to be skipped.  The physical ordering of the attributes in the class definition
  //                   would have to be changed (easy enough in this case) but the default directly compares floating point types
  //                   (price) for equality, and that should be avoided, in general. For example, if x and y are of type double,
  //                   then x < y is okay but x == y is not.  So these (operator<=> and operator==) explicit definitions are
  //                   provided.
  //
  //                   Also, many ordering (sorting) algorithms, like those used in std::map and std::set, require at least a weak
  //                   ordering of elements. operator<=> provides only a partial ordering when comparing floating point numbers.
  //
  // Weak order:       Objects that compare equal but are not substitutable (identical).  For example, since _price can be within
  //                   EPSILON, Book("Title", "Author", "ISBN", 9.99999) and Book("Title", "Author", "ISBN", 10.00001) are equal but
  //                   they are not identical.  If you ignore case when comparing strings, as another example, Book("Title") and
  //                   Book("title") are equal but they are not identical.
  //
  // See std::weak_ordering    at https://en.cppreference.com/w/cpp/utility/compare/weak_ordering and
  //     std::partial_ordering at https://en.cppreference.com/w/cpp/utility/compare/partial_ordering
  //     The Three-Way Comparison Operator at  http://modernescpp.com/index.php/c-20-the-three-way-comparison-operator
  //     Spaceship (Three way comparison) Operator Demystified https://youtu.be/S9ShnAFmiWM
  //
  //
  // Books are equal if all attributes are equal (or within Epsilon for floating point numbers, like price). Books are ordered
  // (sorted) by ISBN, author, title, then price.

  ///////////////////////// TO-DO (19) //////////////////////////////

  /////////////////////// END-TO-DO (19) ////////////////////////////
}




// operator==
bool Book::operator==( const Book & rhs ) const noexcept
{
  // All attributes must be equal for the two books to be equal to the other.  This can be done in any order, so put the quickest
  // and then the most likely to be different first.

  ///////////////////////// TO-DO (20) //////////////////////////////

  /////////////////////// END-TO-DO (20) ////////////////////////////
}








/*******************************************************************************
**  Insertion and Extraction Operators
*******************************************************************************/

// operator>>
std::istream & operator>>( std::istream & stream, Book & book )
{
  ///////////////////////// TO-DO (21) //////////////////////////////
    /// A lot can go wrong when reading from streams - no permission, wrong types, end of file, etc. Minimal exception guarantee says
    /// there should be no side affects if an error or exception occurs, so let's do our work in a local object and move it into place
    /// at the end if all goes well.
    ///
    /// This function should be symmetrical with operator<< below.  Read what your write, and write what you read
    ///
    ///
    /// Assume fields are separated by commas and string attributes are enclosed with double quotes.  For example:
    ///    ISBN             | Title                 | Author             | Price
    ///    -----------------+-----------------------+--------------------+-----
    ///    "9789998287532",   "Over in the Meadow",   "Ezra Jack Keats",   91.11
    ///
    ///
    /// Hint:  Use std::quoted to read and write quoted strings.  See
    ///        1) https://en.cppreference.com/w/cpp/io/manip/quoted
    ///        2) https://www.youtube.com/watch?v=Mu-GUZuU31A

  /////////////////////// END-TO-DO (21) ////////////////////////////
}




// operator<<
std::ostream & operator<<( std::ostream & stream, const Book & book )
{
  ///////////////////////// TO-DO (22) //////////////////////////////
    /// This function should be symmetrical with operator>> above.  Read what your write, and write what you read

  /////////////////////// END-TO-DO (22) ////////////////////////////
}
