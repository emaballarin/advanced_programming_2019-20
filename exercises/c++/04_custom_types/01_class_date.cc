/**
 * 01_class_date.cc
 * Definition and implementation of the "Date" class.
 * (C) Emanuele Ballarin <emanuele@ballarin.cc>, 2019-*
 *
 * Please note: here, every inline is a manual inline.
**/

// INCLUDES

#include <iostream>


// ENUMS

enum class mth_enum
{
    jan = 1,  // Do count months as humans
    feb,
    mar,
    apr,
    may,
    jun,
    jul,
    aug,
    sep,
    oct,
    nov,
    dec
};


// HELPER FUNCTIONS (decl)

unsigned int days_in(const mth_enum, unsigned int);
bool is_leap(const unsigned int);
mth_enum next_month(const mth_enum);


/*
 * CLASS "DATE"
 */

class Date
{
    public:
    unsigned int day() const;
    mth_enum month() const;
    unsigned int year() const;

    Date(unsigned int in_day, mth_enum in_month, unsigned int in_year);
    void add_days(const unsigned int);


    private:
    unsigned int field_day;
    mth_enum field_month;
    unsigned int field_year;

    void add_one_day();
    void add_one_month();
    void add_one_year();
};

// // // IMPLEMENTATIONS // // //

// Ctor
inline Date::Date(unsigned int in_day, mth_enum in_month, unsigned int in_year) :
    field_day{in_day}, field_month{in_month}, field_year{in_year} {};


// Getters

inline unsigned int Date::day() const
{
    return Date::field_day;
}

inline mth_enum Date::month() const
{
    return Date::field_month;
}

inline unsigned int Date::year() const
{
    return Date::field_year;
}

// Arithmetics
void Date::add_days(const unsigned int days_to_add)
{
    for (unsigned int counter = 1; counter <= days_to_add; counter++)
    {
        Date::add_one_day();
    }
}

inline void Date::add_one_day()
{
    if (Date::field_day != days_in(Date::field_month, Date::field_year))
    {
        Date::field_day++;
    }
    else
    {
        Date::field_day = 1;
        Date::add_one_month();
    }
}

void Date::add_one_month()
{
    if (Date::field_month != mth_enum::dec)
    {
        Date::field_month = next_month(Date::field_month);
    }
    else
    {
        Date::field_month = next_month(Date::field_month);
        Date::add_one_year();
    }
}


inline void Date::add_one_year()
{
    Date::field_year++;
}

/*
 * HELPER FUNCTIONS (impl)
 */


inline bool is_leap(const unsigned int inyear)
{
    if ((inyear % 400u == 0u) || ((inyear % 4u == 0u) && (inyear % 100u != 0u)))
        return true;
    else
        return false;
}


unsigned int days_in(const mth_enum inmonth, unsigned int inyear)
{
    switch (inmonth)  // That's fine.
    {
        case (mth_enum::feb):
        {
            if (!is_leap(inyear))
            {
                return 28;
            }
            else
            {
                return 29;
            }
        }

        case (mth_enum::apr):
            return 30;

        case (mth_enum::jun):
            return 30;

        case (mth_enum::sep):
            return 30;

        case (mth_enum::nov):
            return 30;

        default:
            return 31;
    }
}


// It may be cumbersome; yet it serves the purpose of safety!
mth_enum next_month(const mth_enum inmonth)
{
    switch (inmonth)
    {
        case (mth_enum::jan):
            return mth_enum::feb;

        case (mth_enum::feb):
            return mth_enum::mar;

        case (mth_enum::mar):
            return mth_enum::apr;

        case (mth_enum::apr):
            return mth_enum::may;

        case (mth_enum::may):
            return mth_enum::jun;

        case (mth_enum::jun):
            return mth_enum::jul;

        case (mth_enum::jul):
            return mth_enum::aug;

        case (mth_enum::aug):
            return mth_enum::sep;

        case (mth_enum::sep):
            return mth_enum::oct;

        case (mth_enum::oct):
            return mth_enum::nov;

        case (mth_enum::nov):
            return mth_enum::dec;

        case (mth_enum::dec):
            return mth_enum::jan;
    }
}


/*
 * OVERLOADS
 */

bool operator==(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);
std::ostream& operator<<(std::ostream& os, const Date& d);


inline bool operator==(const Date& lhs, const Date& rhs)
{
    if ((lhs.day() == rhs.day()) && (lhs.month() == rhs.month()) && (lhs.year() == rhs.year()))
    {
        return true;
    }
    else
    {
        return false;
    }
}


inline bool operator!=(const Date& lhs, const Date& rhs)
{
    return !(lhs == rhs);
}


std::ostream& operator<<(std::ostream& os, const Date& d)
{
    os << d.day() << "/" << static_cast<unsigned int>(d.month()) << "/" << d.year();
    return os;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    Date startdate(10, mth_enum::sep, 1995);

    // Test
    std::cout << startdate << std::endl;

    startdate.add_days(10000);

    std::cout << startdate << std::endl;


    return 0;
}
