import { defineConfig } from "vitepress";
import { sidebar } from "./get_sidebar.js";

// CI sets DOCS_BASE and DOCS_HOSTNAME for GitHub Pages project site.
const base = process.env.DOCS_BASE || "/";
const hostname = process.env.DOCS_HOSTNAME || "https://tritrisi.github.io/mavlink-tritri";
const repo = "https://github.com/tritrisi/mavlink-tritri";

export default defineConfig({
  title: "TRITRI MAVLink",
  description: "TRITRI: MAVLink-M plus private COP messages for Speed0 C2",
  base,
  lastUpdated: true,
  cleanUrls: false,
  sitemap: { hostname },
  srcExclude: ["**/_*.md", "scripts/**", "README.md"],

  head: [["link", { rel: "icon", href: `${base}favicon.svg`, type: "image/svg+xml" }]],

  themeConfig: {
    logo: {
      // PNG avoids SVG nesting quirks some browsers hit with the exported mark.
      src: "/site/tritri_logo.png",
      alt: "TRITRI",
    },
    siteTitle: "TRITRI",
    sidebar: sidebar("en"),
    externalLinkIcon: true,
    search: { provider: "local" },
    outline: { level: [2, 3] },

    // Serialized into the client bundle, so it can't close over `repo`.
    editLink: {
      pattern: ({ filePath, frontmatter }) =>
        "https://github.com/tritrisi/mavlink-tritri/edit/main/" +
        (frontmatter.editLink_path || `docs/${filePath}`),
      text: "Edit on GitHub",
    },

    nav: [
      { text: "Messages", link: "/en/messages/tritri.md" },
      { text: "C2 Integration", link: "/C2_INTEGRATION.md" },
      { text: "ID Allocation", link: "/en/guide/id_allocation.md" },
      {
        text: "Resources",
        items: [
          { text: "C library (generated)", link: "https://github.com/tritrisi/mavlink-tritri-c_library_v2" },
          { text: "MAVLink-M upstream", link: "https://github.com/Dronecode/mavlink-military" },
          { text: "MAVLink Guide", link: "https://mavlink.io" },
        ],
      },
    ],

    socialLinks: [{ icon: "github", link: repo }],

    footer: {
      message: "Released under the MIT License.",
      copyright: "Copyright © TRITRI / Dronecode Foundation",
    },
  },
});
