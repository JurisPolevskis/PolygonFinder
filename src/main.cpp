#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "ArgParser.h"
#include "FileParser.h"
#include "Line.h"
#include "Intersector.h"
#include "Graph.h"
#include "PolygonProcessor.h"
#include "Output.h"
#include "Debug.h"

using namespace std;

void printUsage() {
	cout << "TODO:Document usage" << std::endl;
}

bool tryExecute(int argc, char **argv) {
	ArgParser args(argc, argv);
	if(args.cmdOptionExists("-h") || args.cmdOptionExists("--help")){
		Debug::print("Help");
		return false;
	}
	const string &in_filename = args.getCmdOption("-f");
	if (in_filename.empty()){
		Debug::print("filename empty");
		return false;
	}
	const string &out_filename = args.getCmdOption("-o");
	const string &delimiter = args.getCmdOption("-d", "\t");
	if (delimiter.size() > 1) {
		Debug::print("Delimiter \"" + delimiter + "\" size too large:" + to_string(delimiter.size()) );
		return false;
	}
	FileParser input(in_filename);
	lines_t lines = makeLines(input.getIntTable(delimiter[0]));
	Intersector intersector(lines);
	Graph graph(intersector.getIntersections());
	PolygonProcessor processor(graph.getCycles());
	processor.discardMirroredCycles();
	Debug::print("\ndiscardMirroredCycles\n");
	Debug::print(graph.cyclesToString());
	//processor.discardZeroAreaSegmentCycles();
	//Debug::print("\ndiscardZeroAreaSegmentCycles\n");
	//Debug::print(graph.cyclesToString());
	Output output(out_filename);
	//output.print();
	return true;
}

int main(int argc, char **argv)
{
	if (!tryExecute(argc, argv)) {
		printUsage();
	}
    return 0;
}