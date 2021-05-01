# Text-Classifier
Advanced Artificial Inteligence

---
### NAME  

textClassifier  Generates vocabulary, corpus and classifies a text into different types of data.  

---
### SYNOPSIS  

```shell
./textClassifier [-v || -co || -h || -l] [arg ...]  
```

---
### DESCRIPTION  

Generates vocabulary, corpus and classifies a text into different types of data.  

Runs the program with the needed flag for generating vocabulary (-v || --vocabulary), generating  corpus (-co || --corpus), printing usermanual (-h || --help), learning probabilities (-l || --learner) .  

####	Options:  

        -v      (--vocabulary) generates the vocabulary from the input file into
                the output file, excluding words in reserved words file.

                Example: 
                    $ textClassifier -v inputFile outputFile rwFile

                Definition:
                    inputFile   File path with the full data that wants to be processed.
                    outputFile  File path were the program will store the solution.
                    rwFile      File path were the reserved words are stored.


        -co     (--corpus) generates one different corpus per each data type 
                received as argument after the input file and the reserved words 
                file.  

                Example:
                    $ textClassifier -co inputFile rwFile Corpus1 Corpus2 ... CorpusX

                Definition:
                    inputFile   File path with the full data that wants to be processed.
                    rwFile      File path were the reserved words are stored.
                    CorpusX     Name of the data type that wants to be searched and generated
                                corpus at. The input file must have them on the first column
                                and separating the rest of the line with a ",", as if it were
                                at the first column of a csv.


        -h      (--help) prints the user manual for the program.

                Example:
                    $ testClassifier -h


        -l      (--learner) calculates the proabilities for each token for each corpus and
                    stores it into files named as aprendizaje_CORPUS.txt on the output folder.

                Example: 
                    $ textClassifier -l vocFile Corpus1 Corpus2 ... CorpusX

                Definition:
                    vocFile     Vocabulary file generated with --vocabulary option
                    CorpusX     Name of the data type that wants to be searched and generated
                                corpus at. The input file must have them on the first column
                                and separating the rest of the line with a ",", as if it were
                                at the first column of a csv.

#### Exit Status:  
        Returns success unless an error occurs  

---
## AUTHOR  
Written by Adrián Epifanio Rodríguez Hernández.  

---
## REPORTING BUGS  

Report an issue at <https://github.com/AdrianEpi/Text-Classifier>  

---
## COPYRIGHT  
```
    Copyright (c) 2021 Adrián Epifanio  

    Permission is hereby granted, free of charge, to any person obtaining a copy  
    of this software and associated documentation files (the \Software\), to deal  
    in the Software without restriction, including without limitation the rights  
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  
    copies of the Software, and to permit persons to whom the Software is  
    furnished to do so, subject to the following conditions:  

    The above copyright notice and this permission notice shall be included in all  
    copies or substantial portions of the Software.  

    THE SOFTWARE IS PROVIDED \AS IS\, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  
    SOFTWARE.  
```  
