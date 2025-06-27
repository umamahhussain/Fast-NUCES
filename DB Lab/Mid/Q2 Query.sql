
-- Create the Authors table
CREATE TABLE Authors (
    author_id INT PRIMARY KEY,
    author_name VARCHAR(255),
    birth_year INT
);

-- Insert data into the Authors table
INSERT INTO Authors (author_id, author_name, birth_year) VALUES
    (1, 'Jack', 1980),
    (2, 'Williams', 1975),
    (3, 'Mark', 1990),
    (4, 'Hennry', 1985),
    (5, 'James', 1970);

-- Create the Books table with a foreign key reference to Authors
CREATE TABLE Books (
    book_id INT PRIMARY KEY,
    title VARCHAR(255),
    author_id INT,
    publication_year INT,
    price DECIMAL(10, 2),
    FOREIGN KEY (author_id) REFERENCES Authors(author_id)
);

-- Insert data into the Books table
INSERT INTO Books (book_id, title, author_id, publication_year, price) VALUES
    (101, 'Becoming', 1, 2005, 69.99),
    (102, 'The Silent Patient', 2, 2010, 49.99),
    (103, 'A Promised Land', 3, 2020, 79.99),
    (104, 'Greenlights', 4, 2015, 55.99),
    (105, 'Normal People', 5, 2000, 45.99);

-- Create the Customers table
CREATE TABLE Customers (
    customer_id INT PRIMARY KEY,
    customer_name VARCHAR(255),
    email VARCHAR(255)
);

-- Insert data into the Customers table
INSERT INTO Customers (customer_id, customer_name, email) VALUES
    (1001, 'Ahmed', 'ahmed1@gmail.com'),
    (1002, 'ALi', 'ali2@gmail.com'),
    (1003, 'Awais', 'awais3@gmail.com'),
    (1004, 'Bilal', 'bilal4@gmail.com'),
    (1005, 'Saad', 'saad5@gmail.com');

-- Create the Orders table with a foreign key reference to Customers
CREATE TABLE Orders (
    order_id INT PRIMARY KEY,
    customer_id INT,
    order_date DATE,
    FOREIGN KEY (customer_id) REFERENCES Customers(customer_id)
);

-- Insert data into the Orders table
INSERT INTO Orders (order_id, customer_id, order_date) VALUES
    (0011, 1001, '2023-01-15'),
    (0012, 1002, '2023-02-20'),
    (0013, 1003, '2023-03-05'),
    (0014, 1004, '2023-03-10'),
    (0015, 1005, '2023-04-08');

-- Create the OrderItems table with foreign key references to Orders and Books
CREATE TABLE OrderItems (
    item_id INT PRIMARY KEY,
    order_id INT,
    book_id INT,
    quantity INT,
    item_price DECIMAL(10, 2),
    FOREIGN KEY (order_id) REFERENCES Orders(order_id),
    FOREIGN KEY (book_id) REFERENCES Books(book_id)
);

-- Insert data into the OrderItems table
INSERT INTO OrderItems (item_id, order_id, book_id, quantity, item_price) VALUES
    (2001, 0011, 101, 2, 59.99),
    (2002, 0012, 103, 1, 79.99),
    (2003, 0013, 102, 3, 49.99),
    (2004, 0014, 104, 1, 55.99),
    (2005, 0015, 105, 2, 45.99);


