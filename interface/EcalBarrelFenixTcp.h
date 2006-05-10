#ifndef ECAL_BARREL_FENIX_TCP_H
#define ECAL_BARREL_FENIX_TCP_H

#include <SimCalorimetry/EcalTrigPrimAlgos/interface/EcalFenixChip.h>
#include <SimCalorimetry/EcalTrigPrimAlgos/interface/EcalFenixEtTot.h>
#include <SimCalorimetry/EcalTrigPrimAlgos/interface/EcalFenixBypassLin.h>
#include <SimCalorimetry/EcalTrigPrimAlgos/interface/EcalFenixMaxof2.h>
#include <SimCalorimetry/EcalTrigPrimAlgos/interface/EcalFenixTcpFormat.h>
#include <SimCalorimetry/EcalTrigPrimAlgos/interface/EcalFenixFgvbEB.h>
#include <DataFormats/EcalDigi/interface/EcalTriggerPrimitiveDigi.h>
 
using namespace std;

namespace tpg {


  /** 
      \class EcalBarrelFenixTcp
      \brief class representing the Fenix chip, format strip, for the endcap
  */
  class EcalBarrelFenixTcp : public EcalFenixChip {


  public:
    EcalBarrelFenixTcp();
    virtual ~EcalBarrelFenixTcp() ;

    //    void process(std::vector<EcalTriggerPrimitiveSample> tpframetow, EcalTriggerPrimitiveSample tptow);
    void process(std::vector<std::vector<int> > & tpframetow, EcalTriggerPrimitiveDigi & tptow);//steph
    EcalFenixBypassLin *getBypasslin(int i) const {return bypasslin_[i];}
    EcalFenixEtTot *getAdder() const { return  dynamic_cast<EcalFenixEtTot *>(adder_);}
    EcalFenixMaxof2 *getMaxOf2() const {return maxOf2_;}
    EcalFenixTcpFormat *getFormatter() const {return dynamic_cast<EcalFenixTcpFormat *>(formatter_);}
    EcalFenixFgvbEB *getFGVB() const {return dynamic_cast<EcalFenixFgvbEB *>(fgvb_);}

  private:
    enum {nStripsPerTower_ = 5};  //UB FIXME: configure?

    EcalFenixMaxof2 *maxOf2_;
    EcalFenixBypassLin *bypasslin_[nStripsPerTower_];

  };

} /* End of namespace tpg */

#endif
