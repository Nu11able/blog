// .vuepress/config.ts

import { defineUserConfig } from 'vuepress'
import { recoTheme } from 'vuepress-theme-reco'

export default defineUserConfig({
  theme: recoTheme({
    home: "/",
    author: "Kevin",
    authorAvatar: "/avatar2.jpg",
    series: {
      '/vuepress-theme-reco/': [ '/vuepress-theme-reco/introduce', '/vuepress-theme-reco/usage' ]
    },
    navbar: [
      { text: 'Home', link: '/', icon: 'reco-home' },
      { text: 'TimeLine', link: '/timeline/', icon: 'reco-date' },
      { text: "GitHub", link: "https://github.com/BigGrayWolf", icon: "reco-github"}
    ],
    // 自动设置分类
    autoSetBlogCategories: true,
    autoAddCategoryToNavbar: false,
  })
})