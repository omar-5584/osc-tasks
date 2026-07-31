
using System.Collections;

namespace handsonSes4
{
    internal partial class Program
    {
        static void Main(string[] args)
        {
            #region DATA
            // Existing orders
            var orders = new List<Order>
        {
            new Order { Id = 1, CustomerName = "Mariam", TotalAmount = 150.0m, IsDelivered = true, Items = new List<string>{ "Laptop", "Mouse" } },
            new Order { Id = 2, CustomerName = "Poula", TotalAmount = 45.0m, IsDelivered = false, Items = new List<string>{ "Book" } },
            new Order { Id = 3, CustomerName = "Marwa", TotalAmount = 210.0m, IsDelivered = true, Items = new List<string>{ "Monitor", "Keyboard", "HDMI Cable" } },
            new Order { Id = 4, CustomerName = "Ibrahin", TotalAmount = 80.0m, IsDelivered = false, Items = new List<string>{ "Headphones" } }
        };

            // New data for exercises
            var customers = new List<Customer>
        {
            new Customer { Name = "Mariam", City = "Cairo", IsActive = true },
            new Customer { Name = "Poula", City = "Alexandria", IsActive = true },
            new Customer { Name = "Marwa", City = "Giza", IsActive = false },
            new Customer { Name = "Ibrahin", City = "Cairo", IsActive = true },
            new Customer { Name = "Sara", City = "Alexandria", IsActive = true }
        };

            var newOrders = new List<Order>
        {
            new Order { Id = 5, CustomerName = "Sara", TotalAmount = 300.0m, IsDelivered = true, Items = new List<string>{ "Printer", "Paper", "Ink" } },
            new Order { Id = 6, CustomerName = "Mariam", TotalAmount = 95.0m, IsDelivered = false, Items = new List<string>{ "Tablet" } },
            new Order { Id = 7, CustomerName = "John", TotalAmount = 120.0m, IsDelivered = true, Items = new List<string>{ "Desk" } }
        };
            var products = new List<Product>
        {
            new Product { Name = "Laptop", Price = 899.99m, Category = "Electronics", StockQuantity = 5 },
            new Product { Name = "Mouse", Price = 29.99m, Category = "Electronics", StockQuantity = 20 },
            new Product { Name = "Book", Price = 15.99m, Category = "Books", StockQuantity = 50 },
            new Product { Name = "Monitor", Price = 199.99m, Category = "Electronics", StockQuantity = 3 },
            new Product { Name = "Keyboard", Price = 49.99m, Category = "Electronics", StockQuantity = 8 },
            new Product { Name = "HDMI Cable", Price = 12.99m, Category = "Accessories", StockQuantity = 30 },
            new Product { Name = "Headphones", Price = 59.99m, Category = "Accessories", StockQuantity = 12 }
        };
            #endregion

            #region HANDSON 1
            // ----- YOUR EXERCISES START HERE -----
            Console.WriteLine("=== Hands-On Lab 1: Advanced LINQ Queries ===\n");

            #region // TODO 1: Group customers by city and count total orders per city

            #region methon syntax

            var synt_groupCust = customers.Join(orders,
              customer => customer.Name,
              order => order.CustomerName,
              (customer, order) => new { Cust = customer, Ord = order }
              )

              .GroupBy(joineditem => joineditem.Cust.City)

              .Select(bycite => new
              {

                  bycite.Key,
                  totalamount = bycite.Count(),
              }).ToList();


            foreach (var ITem in synt_groupCust)
            {
                Console.WriteLine(ITem.Key + " :" + ITem.totalamount);
            }
            #endregion


            #region query syntax

            var query_groupCust = (from order in orders
                                   join customer in customers
                                   on order.CustomerName equals customer.Name
                                   group order by customer.City into cityGroup
                                   select new
                                   {
                                       City = cityGroup.Key,
                                       TotalOrders = cityGroup.Count()
                                   }).ToList();



            #endregion

            #endregion


            #region // TODO 2: Join orders with customers and filter active customers only
            // Create a query that returns all orders from active customers

            #region// method syntax
            var query_activeorders_method = orders.Join(customers,
                order => order.CustomerName,
                customer => customer.Name,
                (order, customer) => new { Order = order, Customer = customer }
                )
                .Where(joined => joined.Customer.IsActive)
                .Select(joined => joined.Order)
                .ToList();

            #endregion

            #region // query syntax
            var query_activeorders_query = (from order in orders
                                            join customer in customers
                                            on order.CustomerName equals customer.Name
                                            where customer.IsActive
                                            select order).ToList();

            #endregion
            #endregion


            #region// TODO 3: Set Operations - Combine orders with new orders
            // Use Union to combine all orders and handle duplicates
            #region method syntax

            var combinedOrders_method = orders.Union(newOrders).ToList();

            #endregion


            #endregion



            #region// TODO 4: Find common items between delivered and undelivered orders


            #region// method syntax
            var method_delivereditems = orders
                .Where(o => o.IsDelivered)
                .SelectMany(o => o.Items);


            var method_notdelivereditems = orders
                .Where(o => !o.IsDelivered)
                .SelectMany(o => o.Items);

            var commonItems = method_delivereditems
                .Intersect(method_notdelivereditems)
                .ToList();

            #endregion

            #region // query syntax
            var query_commonItems = (from order in orders
                                     where order.IsDelivered
                                     from item in order.Items
                                     select item)
                  .Intersect(
                      from order in orders
                      where !order.IsDelivered
                      from item in order.Items
                      select item
                  )
                  .ToList();
            #endregion


            #endregion



            #region// TODO 5: Group orders by customer and aggregate
            // Create a grouping that shows each customer's total spending and average order value


            #region// method syntax
            var method_groupedOrders = orders
                .GroupBy(o => o.CustomerName)
                .Select(g => new
                {
                    CustomerName = g.Key,
                    TotalSpending = g.Sum(o => o.TotalAmount),
                    AverageOrderValue = g.Average(o => o.TotalAmount)
                })
                .ToList();

            #endregion

            #region // query syntax

            var query_groupedOrders = (from order in orders
                                       group order by order.CustomerName into customerGroup
                                       select new
                                       {
                                           CustomerName = customerGroup.Key,
                                           TotalSpending = customerGroup.Sum(o => o.TotalAmount),
                                           AverageOrderValue = customerGroup.Average(o => o.TotalAmount)
                                       }).ToList();
            #endregion


            #endregion

            #region// Bonus TODO: Find customers who ordered but aren't in the customer list
            // Use Except to find mismatched customer names
            #region method syntax
            var orderedCustomerNames = orders.Select(o => o.CustomerName).Distinct();
            var customerNames = customers.Select(c => c.Name).Distinct();
            var mismatchedCustomerNames = orderedCustomerNames.Except(customerNames).ToList();

            #endregion
            #region query syntax
            var orderCustomerNames = (from o in orders.Concat(newOrders)
                                      select o.CustomerName).Distinct();

            var existingCustomerNames = from c in customers
                                        select c.Name;

            var missingCustomers = orderCustomerNames.Except(existingCustomerNames).ToList();
            #endregion

            #endregion

            #endregion

            #region HANDSON 2

            #region// TODO 1: Use Zip to pair orders with products by index
            var zippedOrdersProducts = orders.Zip(products, (order, product) => new { Order = order, Product = product }).ToList();

            #endregion

            #region // TODO 2: Use Concat to combine item lists

            var existingItems = orders.SelectMany(o => o.Items);
            var newItems = newOrders.SelectMany(o => o.Items);
            var allItems = existingItems.Concat(newItems).ToList();

            #endregion

            #region// TODO 3: Use SequenceEqual to compare lists
            var areOrdersEqual = orders.SequenceEqual(newOrders);
            #endregion

            #region// TODO 4: Complex aggregation with Aggregate

            var final = orders.Aggregate(
                new { totalrev = 0.0m, maxorder = 0.0m },
                (acc, order) => new
                {
                    totalrev = acc.totalrev + order.TotalAmount,
                    maxorder = Math.Max(acc.maxorder, order.TotalAmount)

                }
                );

            #endregion

            #region// TODO 5: Multiple aggregations at once

            var multi_final = orders.GroupBy(o => 1) // Grouping by a constant to aggregate all orders together
                .Select(g => new
                {
                    TotalRevenue = g.Sum(o => o.TotalAmount),
                    AverageOrderValue = g.Average(o => o.TotalAmount),
                    MaxOrderValue = g.Max(o => o.TotalAmount),
                    MinOrderValue = g.Min(o => o.TotalAmount)
                })
                .FirstOrDefault();


            #endregion

            #region// TODO 6: Convert to Dictionary with custom key
            Dictionary<int,string>order_cust= orders.ToDictionary(o=>o.Id,o=>o.CustomerName);
            
            
            #endregion

            #region// TODO 7: Cast and OfType examples
            ArrayList mixedList = new ArrayList { 1, "two", 3.0, "four", 5 };

            var strings = mixedList.OfType<string>().ToList();
            var ints = mixedList.OfType<int>().ToList();
            #endregion

            #region// Bonus: Reverse and custom ordering
            
            var reversedOrders = orders.AsEnumerable().Reverse().ToList();
            var orderedByAmount = orders.OrderByDescending(o => o.TotalAmount).ToList();

            #endregion
            #region// ---- Final Challenge: Combine everything ----

            // Your challenge: Create a pipeline that:
            // 1. Filters orders from the last 7 days
            // 2. Groups by category
            // 3. Calculates total revenue per category
            // 4. Converts to a dictionary
            // 5. Formats the output nicely

            var finalchallenge=orders.Concat(newOrders)
                .Where(o => o.IsDelivered) 
                .SelectMany(o => o.Items)
                .Join(products, item => item, product => product.Name, (item, product) => new { Item = item, Product = product })
                .GroupBy(joined => joined.Product.Category)
                .ToDictionary(
                    g => g.Key,
                    g => new
                    {
                        TotalRevenue = g.Sum(joined => joined.Product.Price)
                    }
                );


            foreach (var item in finalchallenge)
            {
                Console.WriteLine($"Category: {item.Key,-15} | Revenue: {item.Value.TotalRevenue:C}");
            }
            #endregion


            #endregion
        }
    }

}
