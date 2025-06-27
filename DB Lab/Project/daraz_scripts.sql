-- Create the database for your Daraz-like project
CREATE DATABASE daraz;

-- Use the database
USE daraz;

-- Create the Users table to store user information
CREATE TABLE Users 
(
    users_id INT PRIMARY KEY,
    username VARCHAR(50) NOT NULL,
    email VARCHAR(100) NOT NULL UNIQUE,
    password VARCHAR(255) NOT NULL,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    phone_number VARCHAR(20)
);

-- Create the Categories table to store product categories
CREATE TABLE Categories 
(
    category_id INT PRIMARY KEY,
    category_name VARCHAR(50) NOT NULL
);

-- Create the Products table to store product information
CREATE TABLE Products 
(
    product_id INT PRIMARY KEY,
    product_name VARCHAR(100) NOT NULL UNIQUE,
    product_description TEXT,
    price DECIMAL(10, 2) NOT NULL,
    stock_quantity INT NOT NULL,
    category_id INT NOT NULL,
    FOREIGN KEY (category_id) REFERENCES Categories(category_id)
);

-- Create the Orders table to store order information
CREATE TABLE Orders (
    order_id INT PRIMARY KEY,
    users_id INT NOT NULL,
    order_date DATE,
    orderstatus VARCHAR(100) NOT NULL,
	product_id INT NOT NULL,
	quantity INT NOT NULL,
    total_price DECIMAL(10, 2) NOT NULL,
    FOREIGN KEY (users_id) REFERENCES Users(users_id),
	FOREIGN KEY (product_id) REFERENCES Products(product_id)
);


-- Create the Reviews table to store product reviews
CREATE TABLE Reviews (
    review_id INT PRIMARY KEY,
    users_id INT NOT NULL,
    product_id INT NOT NULL,
    rating TINYINT NOT NULL,
    comment TEXT,
    date DATE,
    FOREIGN KEY (users_id) REFERENCES Users(users_id),
    FOREIGN KEY (product_id) REFERENCES Products(product_id)
);

-- Create the Images table to store product images
CREATE TABLE Images (
    image_id INT PRIMARY KEY,
    product_id INT NOT NULL,
    image_url VARCHAR(255) NOT NULL,
    FOREIGN KEY (product_id) REFERENCES Products(product_id)
);

-- Users
INSERT INTO Users (users_id, username, email, password, first_name, last_name, phone_number)
VALUES
    (1, 'ali123', 'ali123@email.com', 'password123', 'Ali', 'Khan',  '+92 300-123-4567'),
    (2, 'sana456', 'sana456@email.com', 'password456', 'Sana', 'Ahmed',  '+92 321-987-6543'),
    (3, 'umer789', 'umer789@email.com', 'password789', 'Umer', 'Raza',  '+92 333-111-2222');

-- Categories
INSERT INTO Categories (category_id, category_name)
VALUES
    (1, 'Mobile Phones'),
    (2, 'Fashion'),
    (3, 'Home Appliances'),
    (4, 'Beauty & Personal Care'),
    (5, 'Sports & Outdoors');

-- Products
INSERT INTO Products (product_id, product_name, product_description, price, stock_quantity, category_id)
VALUES
    (1, 'Samsung Galaxy S22', 'Flagship smartphone with cutting-edge features.', 1199.99, 50, 1),
    (2, 'Traditional Shalwar Kameez', 'Elegant and comfortable clothing for men and women.', 39.99, 100, 2),
    (3, 'Refrigerator', 'High-capacity refrigerator with advanced cooling technology.', 699.99, 30, 3),
    (4, 'Skin Care Set', 'Complete set for healthy and glowing skin.', 29.99, 150, 4),
    (5, 'Cricket Kit', 'Quality cricket kit for sports enthusiasts.', 149.99, 50, 5);

-- Orders
INSERT INTO Orders (order_id, users_id, order_date, orderstatus,product_id,total_price,quantity)
VALUES
    (1, 1, '2023-11-02', 'shipped',1,1199.99,1),
    (2, 2, '2023-10-15', 'processing',2,39.99,1),
    (3, 1, '2023-09-25', 'delivered',5,149.99,1);


-- Reviews
INSERT INTO Reviews (review_id, users_id, product_id, rating, comment, date)
VALUES
    (1, 1, 1, 5, 'Fantastic phone with great camera quality.', '2023-09-25'),
    (2, 2, 3, 4, 'The refrigerator works perfectly.', '2023-08-6'),
    (3, 3, 4, 5, 'I love this skincare set.', '2023-10-07');

-- Images
INSERT INTO Images (image_id, product_id, image_url)
VALUES
    (1, 1, 'https://example.com/images/galaxy-s22.jpg'),
    (2, 3, 'https://example.com/images/refrigerator.jpg'),
    (3, 5, 'https://example.com/images/cricket-kit.jpg');

-- Tables

SELECT * FROM Users;
SELECT * FROM Categories;
SELECT * FROM Products;
SELECT * FROM Orders;
SELECT * FROM Reviews;
SELECT * FROM Images;

