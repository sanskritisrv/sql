# Write your MySQL query statement below
select sales.year, sales.price, Product.product_name
FROM Sales 
left join Product ON  Sales.product_id=Product.product_id;