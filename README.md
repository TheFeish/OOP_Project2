# Object oriented programming project
Project subversion v1.1
1. Updated program to use class to use and manipulate student data.

# Execution times (using vector)

### v1.0 (using struct)

|                 | function\entry number | 100000    | 1000000    |
|-----------------|-----------------------|-----------|------------|
| No optimisation | Execution time        | 1.006340s | 11.213013s |
|                 | File read time        | 0.410983s | 4.053913s  |
|                 | Entry split time      | 0.069923s | 0.648578s  |
|                 | Entry sort time       | 0.360062s | 4.664863s  |
|                 | write to file1 time   | 0.080518s | 0.893604s  |
|                 | write to file2 time   | 0.084853s | 0.952055s  |
| -O1             | Execution time        | 0.444763s | 4.580522s  |
|                 | File read time        | 0.256507s | 2.549559s  |
|                 | Entry split time      | 0.007879s | 0.083385s  |
|                 | Entry sort time       | 0.043668s | 0.587651s  |
|                 | write to file1 time   | 0.069673s | 0.681979s  |
|                 | write to file2 time   | 0.067036s | 0.677947s  |
| -O2             | Execution time        | 0.439277s | 4.512094s  |
|                 | File read time        | 0.252322s | 2.515345s  |
|                 | Entry split time      | 0.009087s | 0.084375s  |
|                 | Entry sort time       | 0.041520s | 0.557512s  |
|                 | write to file1 time   | 0.070132s | 0.665610s  |
|                 | write to file2 time   | 0.066217s | 0.689252s  |
| -O3             | Execution time        | 0.431805s | 4.490884s  |
|                 | File read time        | 0.256267s | 2.520405s  |
|                 | Entry split time      | 0.007705s | 0.085135s  |
|                 | Entry sort time       | 0.038540s | 0.505126s  |
|                 | write to file1 time   | 0.065939s | 0.702079s  |
|                 | write to file2 time   | 0.063353s | 0.678138s  |

### v1.1 (using class)

|                 | function\entry number | 100000    | 1000000    |
|-----------------|-----------------------|-----------|------------|
| No optimisation | Execution time        | 1.140082s | 11.827625s |
|                 | File read time        | 0.478323s | 4.541418s  |
|                 | Entry split time      | 0.064989s | 0.671884s  |
|                 | Entry sort time       | 0.395040s | 4.773139s  |
|                 | write to file1 time   | 0.097268s | 0.893066s  |
|                 | write to file2 time   | 0.104462s | 0.948118s  |
| -O1             | Execution time        | 0.453018s | 4.478018s  |
|                 | File read time        | 0.253276s | 2.521649s  |
|                 | Entry split time      | 0.007573s | 0.088449s  |
|                 | Entry sort time       | 0.058064s | 0.543884s  |
|                 | write to file1 time   | 0.068732s | 0.667888s  |
|                 | write to file2 time   | 0.065374s | 0.656147s  |
| -O2             | Execution time        | 0.445967s | 4.612377s  |
|                 | File read time        | 0.261580s | 2.521348s  |
|                 | Entry split time      | 0.007660s | 0.079751s  |
|                 | Entry sort time       | 0.043498s | 0.713117s  |
|                 | write to file1 time   | 0.067731s | 0.660715s  |
|                 | write to file2 time   | 0.065498s | 0.63744s   |
| -O3             | Execution time        | 0.442910s | 4.465847s  |
|                 | File read time        | 0.255935s | 2.510127s  |
|                 | Entry split time      | 0.008533s | 0.079191s  |
|                 | Entry sort time       | 0.045702s | 0.559954s  |
|                 | write to file1 time   | 0.067416s | 0.666963s  |
|                 | write to file2 time   | 0.065324s | 0.649612s  |
