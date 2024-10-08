﻿using System;

namespace DesignPatterns_For_CSharp.Creational_Patterns.Prototype
{
    [Serializable]
    public class Shape(string id, string type) : ICloneable
    {
        public string ID => id;
        public string Type => type;
        public virtual void Draw() { }
        public virtual void Fill(string color) { }
        public object Clone() => MemberwiseClone();
    }
    public class Circle : Shape
    {
        public Circle(string id, string type) : base(id, type) { }
        public override void Draw() => Console.WriteLine("Draw a Circle");
        public override void Fill(string color) => Console.WriteLine("Fill with " + color);
    }
    public class Square : Shape
    {
        public Square(string id, string type) : base(id, type) { }
        public override void Draw() => Console.WriteLine("Draw a Square");
        public override void Fill(string color) => Console.WriteLine("Fill with " + color);
    }
    public class Rectangle : Shape
    {
        public Rectangle(string id, string type) : base(id, type) { }
        public override void Draw() => Console.WriteLine("Draw a Rectangle");
        public override void Fill(string color) => Console.WriteLine("Fill with " + color);
    }
}
