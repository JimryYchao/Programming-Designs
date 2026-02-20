#include <stdlib.h>
#include <string.h>
#include "flyweight_factory.h"

// 单例实例
static FlyweightFactory *instance = NULL;

// 查找颜色节点
static ColorNode *find_color_node(FlyweightFactory *factory, const char *color)
{
    ColorNode *current = factory->colorHead;
    while (current)
    {
        if (strcmp(current->color, color) == 0)
            return current;
        current = current->next;
    }
    return NULL;
}

// 查找半径节点
static RadiusNode *find_radius_node(ColorNode *colorNode, float radius)
{
    RadiusNode *current = colorNode->radiusHead;
    while (current)
    {
        if (current->radius == radius)
            return current;
        current = current->next;
    }
    return NULL;
}

// 创建颜色节点
static ColorNode *create_color_node(const char *color)
{
    ColorNode *node = (ColorNode *)malloc(sizeof(ColorNode));
    if (node)
    {
        node->color = color;
        node->radiusHead = NULL;
        node->next = NULL;
    }
    return node;
}

// 创建半径节点
static RadiusNode *create_radius_node(float radius, CircleData *data)
{
    RadiusNode *node = (RadiusNode *)malloc(sizeof(RadiusNode));
    if (node)
    {
        node->radius = radius;
        node->data = data;
        node->next = NULL;
    }
    return node;
}

// 获取圆形
static IShape *FlyweightFactory_get_circle(const char *color, float radius, float x, float y)
{
    CircleData *data = NULL;
    IShape *shape = NULL;
    // 查找颜色节点
    ColorNode *colorNode = find_color_node(instance, color);
    if (colorNode)
    {
        // 查找半径节点
        RadiusNode *radiusNode = find_radius_node(colorNode, radius);
        if (radiusNode)
            // 复用已有的 CircleData
            return instance->circleFactory.get_circle_by_data(radiusNode->data, x, y);
        else
        {
            shape = instance->circleFactory.get_circle(color, radius, x, y);
            if (shape)
            {
                Circle *circle = (Circle *)shape;
                RadiusNode *newRadiusNode = create_radius_node(radius, circle->data);
                if (newRadiusNode)
                {
                    newRadiusNode->next = colorNode->radiusHead;
                    colorNode->radiusHead = newRadiusNode;
                }
            }
        }
    }
    else
    {
        // 创建新的圆形
        shape = instance->circleFactory.get_circle(color, radius, x, y);
        if (shape)
        {
            Circle *circle = (Circle *)shape;
            colorNode = create_color_node(color);
            if (colorNode)
            {
                colorNode->next = instance->colorHead;
                instance->colorHead = colorNode;

                // 添加新的半径节点
                RadiusNode *newRadiusNode = create_radius_node(radius, circle->data);
                if (newRadiusNode)
                {
                    newRadiusNode->next = colorNode->radiusHead;
                    colorNode->radiusHead = newRadiusNode;
                }
            }
        }
    }
    if (shape)
        printf("Create a New Circle Filled with %s\n", color);
    return shape;
}

// 获取特殊圆形
static IShape *FlyweightFactory_get_special_circle(const char *color, float radius, float x, float y)
{
    IShape *shape = instance->get_circle(color, radius, x, y);
    if (shape)
    {
        return instance->circleFactory.get_spacial_circle((Circle *)shape);
    }
    return NULL;
}

// 初始化享元工厂
static void FlyweightFactory_init(FlyweightFactory *factory)
{
    factory->colorHead = NULL;
    CircleFactory_init(&factory->circleFactory);
    factory->get_circle = FlyweightFactory_get_circle;
    factory->get_special_circle = FlyweightFactory_get_special_circle;
}

// 获取享元工厂单例
FlyweightFactory *GetFlyweightFactoryInstance()
{
    if (instance == NULL)
    {
        instance = (FlyweightFactory *)malloc(sizeof(FlyweightFactory));
        if (instance)
        {
            FlyweightFactory_init(instance);
        }
    }
    return instance;
}

// 释放半径节点
static void free_radius_nodes(RadiusNode *head)
{
    while (head)
    {
        RadiusNode *temp = head;
        head = head->next;
        temp->data->destroy(temp->data);
        temp->data = NULL;
        free(temp);
    }
}

// 释放享元工厂资源
void FlyweightFactory_free(FlyweightFactory *factory)
{
    if (factory)
    {
        ColorNode *current = factory->colorHead;
        while (current)
        {
            ColorNode *temp = current;
            current = current->next;
            free_radius_nodes(temp->radiusHead);
            free(temp);
        }
        free(factory);
        instance = NULL;
    }
}
