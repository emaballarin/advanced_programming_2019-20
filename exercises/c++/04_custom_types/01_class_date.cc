/**
 * 01_class_date.cc
 * Definition and implementation of the "Date" class.
 * (C) Emanuele Ballarin <emanuele@ballarin.cc>, 2019-*
 *
 * Please note: here, every inline is a manual inline.
**/

#include <iostream>

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

unsigned int days_in(const mth_enum, unsigned int);
bool is_leap(const unsigned int);

class Date
{
    public:
    unsigned int day() const;
    mth_enum month() const;
    unsigned int year() const;

    Date(unsigned int in_day, mth_enum in_month, unsigned int in_year);
    void add_days(const unsigned int);

    // // //

    private:
    unsigned int field_day;
    mth_enum field_month;
    unsigned int field_year;

    void add_one_day();
    void add_one_month();
    void add_one_year();
};

// // // IMPLEMENTATIONS // // //

//Ctor
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

// Other functions
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


inline void Date::add_one_year()
{
    Date::field_year++;
}


// // // HELPERS // // //


bool is_leap(const unsigned int inyear)
{
    if ((inyear % 400 == 0) || ((inyear % 4 == 0) && (inyear % 100 != 0)))
        return true;
    else
        return false;
}


unsigned int days_in(const mth_enum inmonth, unsigned int inyear)
{
    switch (inmonth)
    {
        case (mth_enum::feb):
        {
            if (!is_leap(inyear))
            {
                return 29;
            }
            else
            {
                return 28;
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
