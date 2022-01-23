module.exports = {
  // 站点配置
  lang: 'zh-CN',
  title: 'silent-coder',
  description: 'blog of a silent coder',

  // 主题和它的配置
  theme: '@vuepress/theme-default',
  themeConfig: {
    logo: 'images/logo.jpg',
    lastUpdated: true,
    navbar: [
      // NavbarItem
      {
        text: '首页',
        link: '/',
      },
      {
        text: 'GitHub',
        link: 'https://github.com/InThe-Darkness',
      },

    ],
    sidebar: 'auto',
  },

  plugins: [
    [
      '@vuepress/plugin-search',
      {
        locales: {
          '/': {
            placeholder: 'Search',
          },
          '/zh/': {
            placeholder: '搜索',
          },
        },
      },
    ],
  ],
}