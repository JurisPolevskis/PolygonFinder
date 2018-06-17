#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "ArgParser.h"
#include "FileParser.h"
#include "Line.h"
#include "Intersector.h"
#include "Graph.h"
//#include "PolygonProcessor.h"

using namespace std;

void printUsage() {
	cout << "TODO:Document usage";
}

int main(int argc, char **argv){
	ArgParser args(argc, argv);
	if(args.cmdOptionExists("-h") || args.cmdOptionExists("--help")){
		printUsage();
		return 0;
	}
	const string &in_filename = args.getCmdOption("-f");
	const string &out_filename = args.getCmdOption("-o");
	const string &delimiters = args.getCmdOption("-d");
	if (!in_filename.empty()){
		FileParser input(in_filename);
		lines_t lines = makeLines(input.getIntTable(delimiters));
		Intersector intersector(lines);
		Graph graph(intersector.getIntersections());
		//PolygonProcessor processor(graph.getCycles(), lines);
		//processor.discardZeroLengthSides();
		//processor.discardZeroAreaPolygons();
		//Output output(out_filename);
		//output.print(processor.printPolygons());
	}
	else {
		printUsage();
	}
    return 0;
}