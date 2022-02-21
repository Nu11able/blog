import os
import sys
import os

headerstr = '''---
home: true
heroImage: /images/background.png
heroText: 闲看花开，静待花落，冷暖自知，干净如始。
tagline: Stay hungry Stay foolish
actionText: 快速上手 →
actionLink: /zh/guide/

# features:
# - title: c++
#   details: c++技术总结
#   link: /c++
# - title: nginx
#   details: nginx源码阅读以及一些相关的使用总结
#   link: /nginx
# - title: 其它
#   details: 技术文档、教程、技巧、总结等文章
#   link: /other
# - title: c++
#   details: c++技术总结
#   link: /c++
# - title: nginx
#   details: nginx源码阅读以及一些相关的使用总结
#   link: /nginx
# - title: 其它
#   details: 技术文档、教程、技巧、总结等文章
#   link: /other
---
'''

readme = open("docs/readme.md", "w", encoding="utf-8")
readme.write(headerstr)

for dir in os.listdir("docs"):
    if dir.startswith(".") or dir.endswith(".md"):
        continue

    readme.write(f"# {dir}\n")
    for file in os.listdir(f"docs/{dir}"):
        readme.write(f"[{file}]({dir}/{file})\n\n")
    