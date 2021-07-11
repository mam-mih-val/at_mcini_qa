//
// Created by mikhail on 8/11/20.
//

#ifndef QUALITY_ASSURANCE_SRC_BRANCHES_QA_H_
#define QUALITY_ASSURANCE_SRC_BRANCHES_QA_H_

#include "AnalysisTreeQA/Manager.hpp"
#include "AnalysisTreeQA/Task.hpp"
#include "AnalysisTree/Variable.hpp"
#include <AnalysisTree/Cuts.hpp>

#include <centrality.h>

namespace AnalysisTree{

void AddEventHeaderQA(QA::Task* qa_manager);
void AddParticlesQA(QA::Task* qa_manager, int pdg_code);

}

#endif // QUALITY_ASSURANCE_SRC_BRANCHES_QA_H_
