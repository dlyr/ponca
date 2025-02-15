/*
 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#pragma once

namespace Ponca
{
   /*!
      Enum corresponding to the state of a fitting method (and what the finalize function can return
    */
    enum FIT_RESULT : unsigned char
    {
        /*! \brief The fitting is stable an ready to use (and having more than 6
          neighbours)*/
        STABLE    = 0,
        /*! \brief The fitting is ready to use but it can be unstable (and
          having between 3 and 6 neighbors)*/
        UNSTABLE  = 1,
        /*! \brief The fitting is undefined, you can't use it for valid results
          (and having less than 3 neighbors)*/
        UNDEFINED = 2,
        /*! \brief The fitting procedure needs to analyse the neighborhood
          another time*/
        NEED_OTHER_PASS = 3,
        /*! \brief Multiple classes of the fitting procedure initialize the primitive. Should be treated as error. */
        CONFLICT_ERROR_FOUND = 4,
        NBMAX /*!< \brief Nb enums */
    };

/// Flags defining which derivatives need to be computed.
/// \warning Flags have to be combined using `|`
enum DiffType: unsigned int
{
FitScaleDer = 0x01,                          /*!< \brief Flag indicating a scale differentiation. */
FitSpaceDer = 0x02,                          /*!< \brief Flag indicating a space differentiation. */
FitScaleSpaceDer = FitScaleDer | FitSpaceDer /*!< \brief Flag indicating a scale-space differentiation. */
};

} //namespace Ponca
