#include "../tasograph/tasograph.h"
#include "../parser/qasm_parser.h"

#include <iostream>

int main() {
  Context *ctx = new Context({GateType::input_qubit, GateType::input_param,
                              GateType::t, GateType::tdg, GateType::cx});
  QASMParser qasm_parser(ctx);
  DAG *dag = nullptr;
  if (!qasm_parser.load_qasm("circuit/example-circuits/t_cx_tdg.qasm", dag)) {
	std::cout << "Parser failed" << std::endl;
  }

  TASOGraph::Graph graph(ctx, *dag);
  graph.to_qasm("temp.qasm", /*print_result=*/true, true);
  graph.draw_circuit("temp.qasm", "temp.png");
}