#ifndef ECAL_V_ADDER_H
#define ECAL_V_ADDER_H
#include <vector>
#include <DataFormats/EcalDigi/interface/EBDataFrame.h>

namespace tpg {

// global type definitions for header defined by Tag entries in ArgoUML
// Result: typedef <typedef_global_header> <tag_value>;

  /**
     \class EcalVAdder

     abstract base class for calculation of Et

  */


class EcalVAdder {
  /* {src_lang=Cpp}*/



 public:
  virtual std::vector<int> process(std::vector<EBDataFrame>) =0;
  };

} /* End of namespace tpg */

#endif
