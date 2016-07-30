# simple-vcf-loader
A very very simple program to manage vcf files and search over them
***
1. Simple to use
2. Like a terminal
3. Save and load vcf files
4. Simple to understand

___

###### **Note** : the numbers aren't valid !

___

### Command line : 
````
Welcome to contact manager.
----------------------------
Command >
````

#### Help command : 
````
Command > help;
+----------------------------------+
+ save    : export vcf file.       +
+ load    : import vcf file.       +
+ show    : display all contacts.  +
+ add     : add new contact.       +
+ remove  : remove contact.        +
+ update  : update exists contact. +
+ search  : search over contacts.  +
+ sort    : sort manually.         +
+----------------------------------+
+ for more help type man <cmd>     +
+----------------------------------+
Press any key ... 
````

##### Adding contact : 
````
Command > add johnny cash -;
Press any key ... 
Command > add linus torvalds +958561545;
Press any key ... 
Command > add ahmadreza zibaei -;  
Press any key ... 
Command >
````

##### Showing list : 
````
Command > show all;
   ------------------------------
   - ID        : 1              - 
   - Firstname : johnny         - 
   - Lastname  : cash           - 
   - Mobile    : -              - 
   ------------------------------
   ------------------------------
   - ID        : 2              - 
   - Firstname : linus          - 
   - Lastname  : torvalds       - 
   - Mobile    : +958561545     - 
   ------------------------------
   ------------------------------
   - ID        : 3              - 
   - Firstname : ahmadreza      - 
   - Lastname  : zibaei         - 
   - Mobile    : -              - 
   ------------------------------
Press any key ... 
````

##### Saving list to vcf file : 
````
Command > save temp.vcf;
Press any key ... 
````

##### Loading list from vcf file :
````
Command > load temp.vcf;
Command > 3 has been loaded ! 
Press any key ... 

Command > show all;
   ------------------------------
   - ID        : 1              - 
   - Firstname : johnny         - 
   - Lastname  : cash           - 
   - Mobile    : -              - 
   ------------------------------
   ------------------------------
   - ID        : 2              - 
   - Firstname : linus          - 
   - Lastname  : torvalds       - 
   - Mobile    : +958561545     - 
   ------------------------------
   ------------------------------
   - ID        : 3              - 
   - Firstname : ahmadreza      - 
   - Lastname  : zibaei         - 
   - Mobile    : -              - 
   ------------------------------
Press any key ... 
````

##### Search over attributes : 
````
Command > search firstname ah;
   ------------------------------
   - ID        : 3              - 
   - Firstname : ahmadreza      - 
   - Lastname  : zibaei         - 
   - Mobile    : -              - 
   ------------------------------
Press any key ... 

Command > search lastname a;
   ------------------------------
   - ID        : 1              - 
   - Firstname : johnny         - 
   - Lastname  : cash           - 
   - Mobile    : -              - 
   ------------------------------
   ------------------------------
   - ID        : 2              - 
   - Firstname : linus          - 
   - Lastname  : torvalds       - 
   - Mobile    : +958561545     - 
   ------------------------------
   ------------------------------
   - ID        : 3              - 
   - Firstname : ahmadreza      - 
   - Lastname  : zibaei         - 
   - Mobile    : -              - 
   ------------------------------
Press any key ... 
````

##### Remove item :
````
Command > remove 1;
Command > index removed ! 
Press any key ... 

Command > remove 2;
Command > index removed ! 
Press any key ... 

Command > show all;
   ------------------------------
   - ID        : 3              - 
   - Firstname : ahmadreza      - 
   - Lastname  : zibaei         - 
   - Mobile    : -              - 
   ------------------------------
Press any key ... 
````

##### Updating item : 
````
Command > update 1;
Error > ID not found !
Press any key ... 

Command > update 3;
Firstname > Ahmadreza
Lastname  > Zibaei
Mobile    > +980000000000 
Press any key ... 
Command > 
````


##### Sort manually :
````
Command > show all;
   ------------------------------
   - ID        : 4              - 
   - Firstname : Ahmadreza      - 
   - Lastname  : Zibaei         - 
   - Mobile    : +980000000000  - 
   ------------------------------
   ------------------------------
   - ID        : 5              - 
   - Firstname : johnny         - 
   - Lastname  : cash           - 
   - Mobile    : -              - 
   ------------------------------
   ------------------------------
   - ID        : 6              - 
   - Firstname : linus          - 
   - Lastname  : torvalds       - 
   - Mobile    : +958561545     - 
   ------------------------------
   ------------------------------
   - ID        : 7              - 
   - Firstname : ahmadreza      - 
   - Lastname  : zibaei         - 
   - Mobile    : -              - 
   ------------------------------
Press any key ... 

Command > sort firstname;
Command > Sorted !
Press any key ... 

Command > show all;
   ------------------------------
   - ID        : 7              - 
   - Firstname : ahmadreza      - 
   - Lastname  : zibaei         - 
   - Mobile    : -              - 
   ------------------------------
   ------------------------------
   - ID        : 6              - 
   - Firstname : linus          - 
   - Lastname  : torvalds       - 
   - Mobile    : +958561545     - 
   ------------------------------
   ------------------------------
   - ID        : 5              - 
   - Firstname : johnny         - 
   - Lastname  : cash           - 
   - Mobile    : -              - 
   ------------------------------
   ------------------------------
   - ID        : 4              - 
   - Firstname : Ahmadreza      - 
   - Lastname  : Zibaei         - 
   - Mobile    : +980000000000  - 
   ------------------------------
Press any key ... 
````
___
# License 

#### MIT License
#### Copyright (c) 2016 Ahmadreza zibaei

> Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

> The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

>THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
