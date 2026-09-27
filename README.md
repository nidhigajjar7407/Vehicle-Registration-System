<html>
  <head></head>
  <body>
    <h1> Vehicle Registration System </h1>
  </hr>
    <ul>
      <li><h2>Project Description</h2></li>
    </hr>
      <p>Vehicle Registry System is a C++ project used to manage and store information about different types of vehicles. The system allows the user to add vehicles, view all registered vehicles, search for a vehicle using its ID, and view the total number of vehicle objects created. It is designed using several important Object-Oriented Programming (OOP) concepts.</p>
    </hr>
      <li><h2>What is included in this project </h2></li>
    </hr>
      <ul>
        <li>Sedan</li>
        <li>Suv</li>
        <li>Electric Car</li>
        <li>Sports Car</li>
        <li> Flying Car</li>
        <li>Add a Vehicle</li>
        <li>View All Vehicles</li>
        <li>Search Vehicle by ID</li>
        <li>Total Vehicle Counter</li>
        <li>Exit</li>
      </ul>
    </hr>
      <li><h2>How this project is made</h2></li>
    </hr>
      <p>The project starts with a Vehicle base class. It contains common information such as vehicle ID, manufacturer, model, and year. It also contains a static variable called totalVehicles, which counts the created vehicle objects. Then, a Car class inherits from Vehicle. It adds the common car property fuel type. After that, different vehicle classes are created from Car, such as Sedan, SUV, and ElectricCar. The SportsCar class inherits from ElectricCar, so it gets the vehicle, car, and electric-car features and additionally stores the top speed. The FlyingCar uses multiple inheritance because it inherits from both Car and Aircraft. The Aircraft class provides the flight range. Finally, the VehicleRegistry class manages all the vehicles using an array of Vehicle* pointers. This allows different vehicle types to be stored together and their overridden displayDetails() functions to be called correctly.</p>
    </hr>
    </ul>
    <h2> Thank you...! </h2>
  </body>
</html>
