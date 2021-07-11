//
// Created by mikhail on 5/27/20.
//

#include <iostream>

#include <boost/program_options.hpp>

#include <AnalysisTree/DataHeader.hpp>
#include <cuts.h>

#include "branches_qa.h"

int main(int argv, char **argc){
  namespace po = boost::program_options;
  if( argv < 2 ){
    throw std::runtime_error( "No arguments are specified. Try ./run_qa --help for more information" );
  }
  std::string input_list;
  std::string tree_name{"hades_analysis_tree"};
  std::string output_file{"output.root"};
  int n_events{-1};
  po::options_description options("Options");
  options.add_options()
      ("help,h", "Help screen")
      ("input,i", po::value<std::string>(&input_list),
       "Input file list")
      ("tree-name", po::value<std::string>(&tree_name),
       "Input tree name")
      ("output,o", po::value<std::string>(&output_file),
       "Name of output file")
      ("events,N", po::value<int>(&n_events),
       "Number of analysing events");
  po::variables_map vm;
  po::parsed_options parsed = po::command_line_parser(argv, argc).options(options).run();
  po::store(parsed, vm);
  po::notify(vm);
  if (vm.count("help")){
    std::cout << options << std::endl;
    return 0;
  }

  if( std::empty(input_list) )
    throw std::runtime_error( "Input file is not specified. Try ./run_qa --help for more information" );
  AnalysisTree::QA::Manager qa_manager({input_list}, {tree_name});
  qa_manager.SetOutFileName(output_file);
  auto* qa_task = new AnalysisTree::QA::Task;
  AnalysisTree::AddEventHeaderQA(qa_task);
  AnalysisTree::AddParticlesQA(qa_task, 2212);
  AnalysisTree::AddParticlesQA(qa_task, 211);
  AnalysisTree::AddParticlesQA(qa_task, -211);
  qa_manager.AddTask(qa_task);
  qa_manager.Init();
  qa_manager.Run(n_events);
  qa_manager.Finish();
  return 0;
}