import DefaultTheme from "vitepress/theme";
import { inBrowser } from "vitepress";
import { h, onMounted } from "vue";
import HeroInfo from "./components/HeroInfo.vue";
import "./style.css";

export default {
  extends: DefaultTheme,
  Layout: () =>
    h(DefaultTheme.Layout, null, {
      // Logo + title as the first hero content (not under the action buttons).
      "home-hero-info": () => h(HeroInfo),
    }),
  setup() {
    // The generated message pages are long enough that the initial anchor jump
    // can land off target once fonts and layout settle. Re-scroll on first load
    // (same workaround as the MAVLink devguide).
    onMounted(() => {
      if (!inBrowser || !location.hash) return;
      const id = decodeURIComponent(location.hash.slice(1));
      const loaded =
        document.readyState === "complete"
          ? Promise.resolve()
          : new Promise((r) => window.addEventListener("load", r, { once: true }));
      Promise.all([document.fonts?.ready ?? Promise.resolve(), loaded]).then(() =>
        requestAnimationFrame(() => document.getElementById(id)?.scrollIntoView())
      );
    });
  },
};
