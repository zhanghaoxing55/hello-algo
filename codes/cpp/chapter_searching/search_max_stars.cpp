/**
 * File: search_max_stars.cpp
 * Created Time: 2026-02-28
 * Author: Copilot Agent
 */

#include "../utils/common.hpp"

/* 项目类 */
class Project {
  public:
    string name;  // 项目名称
    int stars;    // 星标数

    Project(string name, int stars) : name(name), stars(stars) {
    }

    string toString() {
        return "Project(name='" + name + "', stars=" + to_string(stars) + ")";
    }
};

/* 线性查找星标最多的项目 */
Project *searchMaxStarsLinear(vector<Project> &projects) {
    if (projects.empty()) {  // 如果列表为空，返回 nullptr
        return nullptr;
    }

    Project *maxProject = &projects[0];  // 初始化最大项目为第一个项目
    // 遍历所有项目
    for (auto &project : projects) {
        if (project.stars > maxProject->stars) {  // 如果当前项目星标更多
            maxProject = &project;  // 更新最大项目
        }
    }
    return maxProject;  // 返回星标最多的项目
}

/* 使用 max_element 查找星标最多的项目 */
Project *searchMaxStarsOptimized(vector<Project> &projects) {
    if (projects.empty()) {  // 如果列表为空，返回 nullptr
        return nullptr;
    }

    // 使用 max_element，根据 stars 属性查找最大项目
    auto it = max_element(projects.begin(), projects.end(),
                          [](const Project &a, const Project &b) { 
                              return a.stars < b.stars; 
                          });
    return &(*it);
}

/* Driver Code */
int main() {
    // 创建项目列表
    vector<Project> projects = {
        Project("hello-algo", 95000),
        Project("pytorch", 82000),
        Project("tensorflow", 185000),
        Project("vue", 207000),
        Project("react", 227000),
        Project("django", 78000),
        Project("flask", 67000)
    };

    cout << "项目列表:" << endl;
    for (const auto &project : projects) {
        cout << "  " << project.name << ": " << project.stars << " 星" << endl;
    }
    cout << endl;

    // 方法一：线性查找
    Project *maxProject = searchMaxStarsLinear(projects);
    cout << "方法一（线性查找）:" << endl;
    cout << "  星标最多的项目是: " << maxProject->name << "，拥有 " << maxProject->stars << " 星" << endl;
    cout << endl;

    // 方法二：使用内置函数
    maxProject = searchMaxStarsOptimized(projects);
    cout << "方法二（使用 max_element）:" << endl;
    cout << "  星标最多的项目是: " << maxProject->name << "，拥有 " << maxProject->stars << " 星" << endl;

    return 0;
}
