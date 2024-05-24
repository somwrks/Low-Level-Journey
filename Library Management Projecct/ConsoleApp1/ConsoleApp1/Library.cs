using System;
using System.Collections.Generic;

namespace LibraryManagement
{
    class Program
    {
        class Book
        {
            public string Title { get; set; }
            public string Author { get; set; }
            public bool IsLent { get; set; }
            public User LentTo { get; set; }

            public Book(string title, string author)
            {
                Title = title;
                Author = author;
                IsLent = false;
                LentTo = null;
            }
        }

        class User
        {
            public string Name { get; set; }

            public User(string name)
            {
                Name = name;
            }
        }

        class Library
        {
            private List<Book> books = new List<Book>();
            private List<User> users = new List<User>();

            public void AddBook(string title, string author)
            {
                books.Add(new Book(title, author));
                Console.WriteLine($"Book '{title}' by {author} added to the library.");
            }

            public void AddUser(string name)
            {
                users.Add(new User(name));
                Console.WriteLine($"User '{name}' added to the system.");
            }

            public void LendBook(string title, string userName)
            {
                Book book = books.Find(b => b.Title == title && !b.IsLent);
                User user = users.Find(u => u.Name == userName);

                if (book != null && user != null)
                {
                    book.IsLent = true;
                    book.LentTo = user;
                    Console.WriteLine($"Book '{title}' lent to {userName}.");
                }
                else
                {
                    Console.WriteLine("Cannot lend book. Either the book is already lent or the user does not exist.");
                }
            }

            public void ReturnBook(string title)
            {
                Book book = books.Find(b => b.Title == title && b.IsLent);

                if (book != null)
                {
                    book.IsLent = false;
                    Console.WriteLine($"Book '{title}' returned by {book.LentTo.Name}.");
                    book.LentTo = null;
                }
                else
                {
                    Console.WriteLine("Cannot return book. The book is either not lent or does not exist.");
                }
            }

            public void DisplayBooks()
            {
                Console.WriteLine("Available Books:");
                foreach (var book in books)
                {
                    if (!book.IsLent)
                    {
                        Console.WriteLine($"- {book.Title} by {book.Author}");
                    }
                }

                Console.WriteLine("Lent Books:");
                foreach (var book in books)
                {
                    if (book.IsLent)
                    {
                        Console.WriteLine($"- {book.Title} by {book.Author}, lent to {book.LentTo.Name}");
                    }
                }
            }
        }

        static void Main(string[] args)
        {
            Library library = new Library();
            while (true)
            {
                Console.WriteLine("Library Management System");
                Console.WriteLine("1. Add Book");
                Console.WriteLine("2. Add User");
                Console.WriteLine("3. Lend Book");
                Console.WriteLine("4. Return Book");
                Console.WriteLine("5. Display Books");
                Console.WriteLine("6. Exit");
                Console.Write("Choose an option: ");
                string choice = Console.ReadLine();

                switch (choice)
                {
                    case "1":
                        Console.Write("Enter book title: ");
                        string title = Console.ReadLine();
                        Console.Write("Enter book author: ");
                        string author = Console.ReadLine();
                        library.AddBook(title, author);
                        break;
                    case "2":
                        Console.Write("Enter user name: ");
                        string name = Console.ReadLine();
                        library.AddUser(name);
                        break;
                    case "3":
                        Console.Write("Enter book title to lend: ");
                        title = Console.ReadLine();
                        Console.Write("Enter user name: ");
                        name = Console.ReadLine();
                        library.LendBook(title, name);
                        break;
                    case "4":
                        Console.Write("Enter book title to return: ");
                        title = Console.ReadLine();
                        library.ReturnBook(title);
                        break;
                    case "5":
                        library.DisplayBooks();
                        break;
                    case "6":
                        return;
                    default:
                        Console.WriteLine("Invalid choice. Please try again.");
                        break;
                }
                Console.WriteLine();
            }
        }
    }
}
