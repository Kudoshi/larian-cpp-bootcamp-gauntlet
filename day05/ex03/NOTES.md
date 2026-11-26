# When NOT to use a pattern

## Singleton, refuse when: creating a system like SettingsManager

- The settings manager is used to load, store and change the settings of the game at runtime
- Singleton might be an OK fit here as you only need one settings manager and it is easy to access the settings if using singleton
- However the issue here is that it becomes difficult to test the settings. If not managed properly, the settings can leak into the next test
 and it is hard to test multiple different settings at one go

Instead: use dependency injection
- Dependency injection is like the opposite of a singleton style where instead of a global-access style, you will have to pass the reference directly into the class requiring it
- This is a better fit as this allows you to easily test multiple different settings config

Testability cost: 
- A singleton settingsmanager is shared across multiple tests whereby if not managed properly can cause issue
- For example if one test changes the game difficulty, that state will remain in the singleton even on the next test unless it is manually changed or reset. This means that the tests will have to depend on set of execution order and ensures the SettingsManager is reset properly otherwise it can cause failures or inconsistency with the test result. 
- With dependency injection, a new SettingsManager can be easily constructed passing it into the class that needs it providing a consistent config of the settings.

## Visitor Pattern, refuse when: unsure of how many types or will have a growing types
- Visitor pattern is great for when you are sure of how many types there will exist. It make things easier when trying to implement new behaviour/logic.
- However, if there will be more types to be added and the behaviour will change frequently then it will be unwise to use it as adding a new type will require you
    to modify the base Visitor interface and then every other behaviour that uses it.

Instead: Use polymorphism

- For example, if lets say an Entity class needs to calculate its own damage, i would define it as a virtual function in the entity class.
    Which then other children class can directly implement its own behaviour. As it is virtual, it doesn't become mandatory to override which allows the children to choose to ignore or implement the behaviour
- Adding a new behaviour that fundamentally doesn't change in any type then becomes easier as you can just add it in without requiring to create additional file and overriding every single behaviour type logic

Testability cost: Adding a new entity type becomes cumbersome

- If you want to test adding a new entity type, you must update every behaviour that uses the visitor class
- For example, if you have 4 entities type and 10 behaviours. Adding a new entity would require you to define and implement the new entity type logic for all 10 behaviours
- With polymorphism, I can just add a new entity and add a virtual functions. Entities that are interested can be implement the function or choose to not implement it saving time in not writing down the declaration for the function. I can also add a new base function that can be easily shared across all type should the behaviour be the same
