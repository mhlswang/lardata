////////////////////////////////////////////////////////////////////////
// \file IDetectorProperties.h
//
// \brief pure virtual base interface for detector properties
//
// \author jpaley@fnal.gov
// 
////////////////////////////////////////////////////////////////////////
#ifndef DATAPROV_IDETECTORPROPERTIES_H
#define DATAPROV_IDETECTORPROPERTIES_H

#include "fhiclcpp/ParameterSet.h"
#include "Geometry/Geometry.h"

///General LArSoft Utilities
namespace dataprov{
  
  class IDetectorProperties {
    public:

      IDetectorProperties(const IDetectorProperties &) = delete;
      IDetectorProperties(IDetectorProperties &&) = delete;
      IDetectorProperties& operator = (const IDetectorProperties &) = delete;
      IDetectorProperties& operator = (IDetectorProperties &&) = delete;
      virtual ~IDetectorProperties() = default;
      
      virtual double Efield(unsigned int planegap=0) const = 0; ///< kV/cm

      virtual double DriftVelocity(double efield=0., double temperature=0.) const = 0;
      
      /// dQ/dX in electrons/cm, returns dE/dX in MeV/cm.
      virtual double BirksCorrection(double dQdX) const = 0;
      virtual double ModBoxCorrection(double dQdX) const = 0;

      virtual double ElectronLifetime() const = 0;
      
      virtual double       SamplingRate()      const = 0;
      virtual double       ElectronsToADC()    const = 0;
      virtual unsigned int NumberTimeSamples() const = 0;
      virtual unsigned int ReadOutWindowSize() const = 0;
      virtual int          TriggerOffset()     const = 0;
      virtual double       TimeOffsetU()       const = 0;
      virtual double       TimeOffsetV()       const = 0;
      virtual double       TimeOffsetZ()       const = 0;

      virtual double       ConvertXToTicks(double X, int p, int t, int c) const = 0;
      virtual double       ConvertXToTicks(double X, geo::PlaneID const& planeid) const = 0;
      virtual double       ConvertTicksToX(double ticks, int p, int t, int c) const = 0;
      virtual double       ConvertTicksToX(double ticks, geo::PlaneID const& planeid) const = 0;
      virtual double       GetXTicksOffset(int p, int t, int c) const = 0;
      virtual double       GetXTicksOffset(geo::PlaneID const& planeid) const = 0;
      virtual double       GetXTicksCoefficient(int t, int c) const = 0;
      virtual double       GetXTicksCoefficient(geo::TPCID const& tpcid) const = 0; 
      virtual double       GetXTicksCoefficient() const = 0;

      // The following methods convert between TDC counts (SimChannel time) and
      // ticks (RawDigit/Wire time).
      virtual double       ConvertTDCToTicks(double tdc) const = 0;
      virtual double       ConvertTicksToTDC(double ticks) const = 0;

      virtual bool         InheritNumberTimeSamples() const = 0;

    protected:
      IDetectorProperties() = default;

    }; // class IDetectorProperties
} //namespace dataprov

#endif // DATAPROV_IDETECTORPROPERTIES_H