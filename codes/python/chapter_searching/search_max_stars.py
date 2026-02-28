"""
File: search_max_stars.py
Created Time: 2026-02-28
Author: Copilot Agent
"""


class Project:
    """项目类"""

    def __init__(self, name: str, stars: int):
        self.name = name  # 项目名称
        self.stars = stars  # 星标数

    def __repr__(self):
        return f"Project(name='{self.name}', stars={self.stars})"


def search_max_stars_linear(projects: list[Project]) -> Project | None:
    """线性查找星标最多的项目"""
    if not projects:  # 如果列表为空，返回 None
        return None

    max_project = projects[0]  # 初始化最大项目为第一个项目
    # 遍历所有项目
    for project in projects:
        if project.stars > max_project.stars:  # 如果当前项目星标更多
            max_project = project  # 更新最大项目
    return max_project  # 返回星标最多的项目


def search_max_stars_optimized(projects: list[Project]) -> Project | None:
    """使用 max 函数查找星标最多的项目"""
    if not projects:  # 如果列表为空，返回 None
        return None

    # 使用 max 函数，根据 stars 属性查找最大项目
    return max(projects, key=lambda p: p.stars)


"""Driver Code"""
if __name__ == "__main__":
    # 创建项目列表
    projects = [
        Project("hello-algo", 95000),
        Project("pytorch", 82000),
        Project("tensorflow", 185000),
        Project("vue", 207000),
        Project("react", 227000),
        Project("django", 78000),
        Project("flask", 67000),
    ]

    print("项目列表:")
    for project in projects:
        print(f"  {project.name}: {project.stars} 星")
    print()

    # 方法一：线性查找
    max_project = search_max_stars_linear(projects)
    print("方法一（线性查找）:")
    print(f"  星标最多的项目是: {max_project.name}，拥有 {max_project.stars} 星")
    print()

    # 方法二：使用内置函数
    max_project = search_max_stars_optimized(projects)
    print("方法二（使用 max 函数）:")
    print(f"  星标最多的项目是: {max_project.name}，拥有 {max_project.stars} 星")
