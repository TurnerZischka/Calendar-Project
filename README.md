  As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
  Prompt text is any lines beginning with "\>"
  Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# Scheduler for da Cool Kids
 
  Authors:   \<[Turner Zischka](https://github.com/TurnerZischka)\>  \<[Austin Lee](https://github.com/austinslee)\> \<[Aly Refaat](https://github.com/Sebesky)\>
 

 
## Project Description
  ## Phase I
  Our project is intended to be a task scheduler with GUI. Our hope is to create a tool that each one of use would want to use in our daily life. Obviously we want to get stuff done, this tool should help with that. Important too is the fact that this is a useful project, while the other suggested projects are games. Games are a popular stable for CS projects, but only a portion of the possible jobs for CS are game devs, in fact some of the worst jobs are game dev jobs. This is meant to be a more helpful tool that allows us to have a stronger resume/portfolio for non-gamedev jobs. 
   * In this application, a user can create tasks including a title, description,
classification (e.g. personal, work, study) priority, duration and due date. Some of these
features can also be optional. Users can also create task lists where each list includes
multiple tasks. Task lists can represent larger tasks that have subtasks within them.
Users can display, edit, and delete tasks and task lists. Users should also be able to
undo these operations.
 
  * Design Patterns Patterns to use
    * Strategy
       * We plan to utilize the Strategy design pattern in order to help implement the display. The program's display is made up of a base class called cell which dictates how the boxes creating the display will look like and based on the tasks scheduled the program will choose a different strategy in order to create different sized boxes. We think this pattern will be a good fit for our program because different sized tasks require different sized boxes and the program has no way of knowing what size to make the box. Through the use of the strategy design pattern, we can create a method that allows the program to choose from different designs to create the correct display.
    * Composite
       * We want to implement a list output of all events a user has entered into their schedule. The user can add events to days, or to weeks, and should be able to output all of them. This pattern is useful because it allows us to nests tasks within tasks, and have them displayed under one command of an interface. Also, this would allow us to create subtasks to tasks, a representation of tasks within a goal. This is a good choice for exactly that nesting puropse. Objects of the same type can be contained with one another, and treated uniformly by an interface. 
    * Command
       * We plan to utilize the Command design pattern in order to implement a menu system to add, remove, and edit tasks. We will create an interface where the user can interact with the menu items which will be tied to a specific command and when that menu item is selected by the user, a command or sequence of commands will be executed. We think this pattern will be a good fit for this feature because the pattern is kind of designed to implement menus and can easily be used for the purpose of our program.
             
  * Programming Languages in use
    * C++
  * Tools in Use
    * [GTest](https://github.com/google/googletest) - used to test functionality of our program before full completion of our program. Useful also for testing first programming. 
    * [Valgrind](https://www.valgrind.org/) - Primarily the Memcheck tool to identify any possible programming errors and memory mismanagements
  * Inputs
    * User data - from menu
    * User data - from textual inputs
  * Outputs
    * Save file data, in order to save user data and dates across boots (using input/output file streams to/from txt files).
    * Graphical Display
       * Can be changed with menu options which affect terminal display
 


 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `Backlog` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA 
  ![alt text](https://github.com/cs100/final-project-alee235-arefa001-tzisc001/blob/master/Calendar%20Class%20Diagram%20(1).png)
  ![alt text](https://github.com/cs100/final-project-alee235-arefa001-tzisc001/blob/master/Calendar%20Class%20Diagram%20-%20Composite.png)
  ![alt text](https://github.com/cs100/final-project-alee235-arefa001-tzisc001/blob/master/Calendar%20Class%20Diagram%20-%20Strategy.png)
  ![alt text](https://github.com/cs100/final-project-alee235-arefa001-tzisc001/blob/master/Calendar%20Class%20Diagram%20-%20Command.png)
## Class Diagram
 > Include a class diagram(s) for each design pattern and a description of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description). 
 

 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.
 


 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
