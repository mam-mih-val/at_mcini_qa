//
// Created by mikhail on 9/21/20.
//

#include "branches_qa.h"

namespace AnalysisTree{

void AddParticlesQA(QA::Task *qa_manager, int pdg_code) {
  Cuts *particle = new Cuts(std::to_string(pdg_code), {SimpleCut({"particles", "pid"}, pdg_code)});

  qa_manager->AddH1({"p_{T}, #frac{GeV}{c}", {"particles", "pT"}, {500, 0.0, 2.5}}, particle);
  qa_manager->AddH1({"#phi, rad", {"particles", "phi"}, {350, -3.5, 3.5}}, particle);

  qa_manager->AddH2({"y_{cm}", {"particles", "rapidity"}, {200, -2.0, 2.0}},
                    {"pt, #frac{GeV}{c}", {"particles", "pT"}, {200, 0.0, 2.5}},
                    particle);

  qa_manager->AddH2({"p, #frac{GeV}{c}", {"particles", "p"}, {250, 0.0, 5.0}},
                    {"#eta", {"particles", "eta"}, {250, -2.5, 2.5}},
                    particle);
  qa_manager->AddH2({"#eta", {"particles", "eta"}, {250, -2.5, 2.5}},
                    {"pt, #frac{GeV}{c}", {"particles", "pT"}, {250, 0.0, 2.5}},
                    particle);
  qa_manager->AddH2({"y_{cm}", {"particles", "rapidity"}, {200, -2.0, 2.0}},
                    {"#phi, [rad]", {"particles", "phi"}, {350, -3.5, 3.5}},
                    particle);
  qa_manager->AddH2({"p, #frac{GeV}{c}", {"particles", "p"}, {250, 0.0, 5.0}},
                    {"#phi, [rad]", {"particles", "phi"}, {315, -3.15, 3.15}}, particle);
}

void AddEventHeaderQA(QA::Task *qa_manager) {
  qa_manager->AddH1({"number of particles", {"event_header", "number_of_particles"}, {150, 394.0, 544}});
  qa_manager->AddH1({"b [fm]", {"event_header", "impact_parameter"}, {200, 0.0, 20.0}});
  qa_manager->AddH1({"Number of participants", {"event_header", "n_part"}, {394, 0.0, 394.0}});
  qa_manager->AddH1({"Number of binary collisions", {"event_header", "n_col"}, {200, 0.0, 2000.0}});
  qa_manager->AddH1({"centrality", {"event_header", "centrality"}, {10, 0.0, 100.0}});
  qa_manager->AddProfile({"centrality", {"event_header", "centrality"}, {10, 0.0, 100.0}},
                         {"b [fm]", {"event_header", "impact_parameter"}, {200, 0.0, 20.0}});
  qa_manager->AddProfile({"centrality", {"event_header", "centrality"}, {10, 0.0, 100.0}},
                         {"Number of participants", {"event_header", "n_part"}, {200, 0.0, 394.0}});
  qa_manager->AddProfile({"centrality", {"event_header", "centrality"}, {10, 0.0, 100.0}},
                         {"Number of binary collisions", {"event_header", "n_col"}, {200, 0.0, 2000.0}});
}

}
