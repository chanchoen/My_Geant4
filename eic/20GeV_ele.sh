source /cvmfs/sft.cern.ch/lcg/releases/LCG_96b/Geant4/10.05.p01.1/x86_64-centos7-gcc8-opt/bin/geant4.sh
source /cvmfs/sft.cern.ch/lcg/releases/LCG_96b/Geant4/10.05.p01.1/x86_64-centos7-gcc8-opt/Geant4-env.sh

export HEPMC_DIR=/cvmfs/sft.cern.ch/lcg/releases/LCG_96b/hepmc3/3.1.2/x86_64-centos7-gcc8-opt
export FASTJET_DIR=/cvmfs/sft.cern.ch/lcg/releases/LCG_96b/fastjet/3.3.2/x86_64-centos7-gcc8-opt
export PYTHIA_DIR=/cvmfs/sft.cern.ch/lcg/releases/LCG_96b/MCGenerators/pythia8/240/x86_64-centos7-gcc8-opt

export PYTHIA8=/cvmfs/sft.cern.ch/lcg/releases/LCG_96b/MCGenerators/pythia8/240/x86_64-centos7-gcc8-opt
export PYTHIA8DATA=/cvmfs/sft.cern.ch/lcg/releases/LCG_96b/MCGenerators/pythia8/240/x86_64-centos7-gcc8-opt/share/Pythia8/xmldoc
export ROOT_INCLUDE_PATH=/cvmfs/sft.cern.ch/lcg/releases/LCG_96b/hepmc3/3.1.2/x86_64-centos7-gcc8-opt/include:$ROOT_INCLUDE_PATH


export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$HEPMC_DIR/lib64:$FASTJET_DIR/lib:$PYTHIA_DIR/lib:$PWD/lib

./bin/DRsim 20GeV_ele.mac $1 Ele_20GeV_v001_2500mm
