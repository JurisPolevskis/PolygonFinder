# PolygonFinder
Interview question: Given file containing line numbers, start and end coordinates output file containing line numbers and vertex coordinates for all possible polygons

Usage: polygf -f <filename> <options>
Options:
        -o <filename> : Output file name
        -d <delimiter> : Delimiter for input file (default: "\t")
        
Input file format:
<(int)line_id><\t><(int)start_x><\t><(int)start_y><\t><(int)end_x><\t><(int)end_y><\n>
...
        
Output format (subject to change);
(<start repeat here>(<(double)segment_start_x>, <(double)segment_start_y>)->(<(double)segment_end_x>, <(double)segment_end_y>):<(int list)line_id> <repeat n times>)<\n> 
...

Functional Overview:
  1) Read integers from csv file
  2) Calculate intersections using https://stackoverflow.com/a/565282 for each line pair
  3) Build intersection graph where each node stores pointers to adjacent nodes and line numbers that connect them
  4) Using deaph first search with backtracking find cycles - potential polygons
  5) Discard cycles which are not distinc polygons:
    5.a) Discard mirrored polygons
    5.b) Discard polygons with zero area segments
    5.c) TODO: Discard polygons whose sides self-intersect
  6) Print output
  
Built with in cygwin64, g++, c++17
Beware of: https://www.mail-archive.com/cygwin@cygwin.com/msg157306.html
