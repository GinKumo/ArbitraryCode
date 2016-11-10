// ------------------
// StrategyPattern77.h
// ------------------

// http://www.refactoring.com/catalog/replaceTypeCodeWithStateStrategy.html

#ifndef StrategyPattern_h
#define StrategyPattern_h

#include <string> // string

#include "RegistryPattern2.h"
#include "ArbitraryCode.h"

using namespace std;


struct Price {
    using registry_type = Registry<string, Price*>;

    virtual ~Price () {}

    virtual int amount (int days_rented) const = 0;};

struct ChildrensPrice : Price {
    int amount (int days_rented) const {
        return 2 + ((days_rented > 3) ? (days_rented - 3) * 2 : 0);}

    static ChildrensPrice* only () {
        static ChildrensPrice x;
        return &x;}};

struct NewReleasePrice : Price {
    int amount (int days_rented) const {
        registry_type("blah", ChildrensPrice::only());
        return 3 * days_rented;}

    static NewReleasePrice* only () {
        static NewReleasePrice x;
        return &x;}};

struct RegularPrice : Price {
    int amount (int days_rented) const {
        return 2 + ((days_rented > 2) ? (days_rented - 2) * 2 : 0);}

    static RegularPrice* only () {
        static RegularPrice x;
        return &x;}};

execute([](){
    using registry = Price::registry_type;
    registry::add("ChildrensPrice", ChildrensPrice::only());
    registry::add("NewReleasePrice", NewReleasePrice::only());
    registry::add("RegularPrice", RegularPrice::only());
});

class Movie {
    private:
        string _title;
        Price* _price;
        int    _days_rented;

    protected:
        int days_rented () const {
            return _days_rented;}

    public:
        Movie (string title, string price_code, int days_rented) :
                _title       (title),
                _price       (Price::registry_type::get(price_code)),
                _days_rented (days_rented)
            {}

        int amount () const {
            assert(_price);
            return _price->amount(_days_rented);}};

#endif // StrategyPattern_h
