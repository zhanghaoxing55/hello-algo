/**
 * File: search_max_stars.java
 * Created Time: 2026-02-28
 * Author: Copilot Agent
 */

package chapter_searching;

import java.util.*;

public class search_max_stars {
    /* 项目类 */
    static class Project {
        String name;  // 项目名称
        int stars;    // 星标数

        Project(String name, int stars) {
            this.name = name;
            this.stars = stars;
        }

        @Override
        public String toString() {
            return "Project(name='" + name + "', stars=" + stars + ")";
        }
    }

    /* 线性查找星标最多的项目 */
    static Project searchMaxStarsLinear(List<Project> projects) {
        if (projects == null || projects.isEmpty()) {  // 如果列表为空，返回 null
            return null;
        }

        Project maxProject = projects.get(0);  // 初始化最大项目为第一个项目
        // 遍历所有项目
        for (Project project : projects) {
            if (project.stars > maxProject.stars) {  // 如果当前项目星标更多
                maxProject = project;  // 更新最大项目
            }
        }
        return maxProject;  // 返回星标最多的项目
    }

    /* 使用 Collections.max 查找星标最多的项目 */
    static Project searchMaxStarsOptimized(List<Project> projects) {
        if (projects == null || projects.isEmpty()) {  // 如果列表为空，返回 null
            return null;
        }

        // 使用 Collections.max，根据 stars 属性查找最大项目
        return Collections.max(projects, Comparator.comparingInt(p -> p.stars));
    }

    public static void main(String[] args) {
        // 创建项目列表
        List<Project> projects = Arrays.asList(
            new Project("hello-algo", 95000),
            new Project("pytorch", 82000),
            new Project("tensorflow", 185000),
            new Project("vue", 207000),
            new Project("react", 227000),
            new Project("django", 78000),
            new Project("flask", 67000)
        );

        System.out.println("项目列表:");
        for (Project project : projects) {
            System.out.println("  " + project.name + ": " + project.stars + " 星");
        }
        System.out.println();

        // 方法一：线性查找
        Project maxProject = searchMaxStarsLinear(projects);
        System.out.println("方法一（线性查找）:");
        System.out.println("  星标最多的项目是: " + maxProject.name + "，拥有 " + maxProject.stars + " 星");
        System.out.println();

        // 方法二：使用内置函数
        maxProject = searchMaxStarsOptimized(projects);
        System.out.println("方法二（使用 Collections.max）:");
        System.out.println("  星标最多的项目是: " + maxProject.name + "，拥有 " + maxProject.stars + " 星");
    }
}
