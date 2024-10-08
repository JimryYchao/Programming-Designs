﻿namespace DesignPatterns_For_CSharp.Structural_Patterns.Bridge
{
    // 桥接对象
    public class Shape
    {
        protected DrawAPI drawAPI;
        public Shape(DrawAPI drawAPI) => this.drawAPI = drawAPI;
        public virtual void Draw(string color)
        {
            drawAPI.Draw();
            drawAPI.Fill(color);
        }
    }
}
