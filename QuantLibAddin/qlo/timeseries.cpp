
/*
 Copyright (C) 2007 Ferdinando Ametrano

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it
 under the terms of the QuantLib license.  You should have received a
 copy of the license along with this program; if not, please email
 <quantlib-dev@lists.sf.net>. The license is also available online at
 <http://quantlib.org/license.shtml>.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

#if defined(HAVE_CONFIG_H)     // Dynamically created by configure
    #include <qlo/config.hpp>
#endif
#include <qlo/timeseries.hpp>
#include <ql/errors.hpp>

namespace QuantLibAddin {

   TimeSeries::TimeSeries(
        const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
        const std::vector<QuantLib::Date>& d,
        const std::vector<QuantLib::Real>& x,
        bool permanent)
   : ObjectHandler::LibraryObject<QuantLib::TimeSeries<QuantLib::Real> >(properties, permanent)
   {
        QL_REQUIRE(x.size()==d.size(),
                  "unmatched size between dates (" << d.size() <<
                  ") and values(" << x.size() << ")");

        libraryObject_ =
            boost::shared_ptr<QuantLib::TimeSeries<QuantLib::Real> >(new
                QuantLib::TimeSeries<QuantLib::Real>(d.begin(),
                                                     d.end(),
                                                     x.begin()));
    }
}