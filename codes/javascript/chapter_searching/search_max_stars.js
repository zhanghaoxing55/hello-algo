/**
 * File: search_max_stars.js
 * Created Time: 2026-02-28
 * Author: Copilot Agent
 */

/* 项目类 */
class Project {
    constructor(name, stars) {
        this.name = name;  // 项目名称
        this.stars = stars;  // 星标数
    }

    toString() {
        return `Project(name='${this.name}', stars=${this.stars})`;
    }
}

/* 线性查找星标最多的项目 */
function searchMaxStarsLinear(projects) {
    if (!projects || projects.length === 0) {  // 如果列表为空，返回 null
        return null;
    }

    let maxProject = projects[0];  // 初始化最大项目为第一个项目
    // 遍历所有项目
    for (const project of projects) {
        if (project.stars > maxProject.stars) {  // 如果当前项目星标更多
            maxProject = project;  // 更新最大项目
        }
    }
    return maxProject;  // 返回星标最多的项目
}

/* 使用 reduce 方法查找星标最多的项目 */
function searchMaxStarsOptimized(projects) {
    if (!projects || projects.length === 0) {  // 如果列表为空，返回 null
        return null;
    }

    // 使用 reduce 方法，根据 stars 属性查找最大项目
    return projects.reduce((max, project) => 
        project.stars > max.stars ? project : max
    );
}

/* Driver Code */
// 创建项目列表
const projects = [
    new Project('hello-algo', 95000),
    new Project('pytorch', 82000),
    new Project('tensorflow', 185000),
    new Project('vue', 207000),
    new Project('react', 227000),
    new Project('django', 78000),
    new Project('flask', 67000)
];

console.log('项目列表:');
for (const project of projects) {
    console.log(`  ${project.name}: ${project.stars} 星`);
}
console.log();

// 方法一：线性查找
let maxProject = searchMaxStarsLinear(projects);
console.log('方法一（线性查找）:');
console.log(`  星标最多的项目是: ${maxProject.name}，拥有 ${maxProject.stars} 星`);
console.log();

// 方法二：使用内置函数
maxProject = searchMaxStarsOptimized(projects);
console.log('方法二（使用 reduce 方法）:');
console.log(`  星标最多的项目是: ${maxProject.name}，拥有 ${maxProject.stars} 星`);
