# CS-210 Portfolio


### Summarize the project and what problem it was solving.

In project 3 for CS-210 I developed a basic grocery-store analytics system using C++. My code processes input data, enables the user to interact with stats drawn from the input data, and saves stats to a "backup" file.

### What did you do particularly well?

I think my methods to readFileToMap() and saveMapToFile() are well done. I wrote code that could easily be reused to process data from different deparments of the grocery store and / or additional data for the produce department.

### Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?

The functions I wrote for analyzing the produce data are limited to analyzing the produceItems map. I could enhance my code by passing a map to each function as a parameter, improving the reusability of the code.

### Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?

The most challenging aspect of the project was putting together the readFileToMap() and saveMapToFile() methods. When I started working on the project, the produceItems map was a public data member of the Sales class, and the operations that occur in those two methods took place in the main method. Making the produceItems map a private data member required refactoring almost everything, which was somewhat challenging.

### What skills from this project will be particularly transferable to other projects or course work?

Wrapping my head around pass-by-reference vs pass-by-value parameters is definitely important knowledge. Learning about Doxygen documentation markup language will also be a worthwhile skill throughout my career.

### How did you make this program maintainable, readable, and adaptable?

I made this project maintainable by writing detailed documentation in the header file, including in-line comments throughout my code. I made it readable by handling much of the logic outside of the main method and by using logical variable / method names consistent with standard best practices. I made it adaptable by writing methods that could easily be applied to additional data sources.
