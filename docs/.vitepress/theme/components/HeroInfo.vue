<script setup>
import { withBase, useData } from "vitepress";

const { frontmatter } = useData();
const hero = frontmatter.value.hero || {};
</script>

<template>
  <div class="hero-info">
    <h1 class="name">
      <img
        class="mark"
        :src="withBase('/site/tritri_logo.png')"
        alt=""
        width="72"
        height="67"
      />
      <span class="clip">{{ hero.name }}</span>
    </h1>
    <p v-if="hero.tagline" class="tagline">{{ hero.tagline }}</p>
  </div>
</template>

<style scoped>
.hero-info .name {
  display: flex;
  align-items: center;
  gap: 16px;
  margin: 0 0 24px;
  font-size: 48px;
  font-weight: 700;
  line-height: 1.15;
  letter-spacing: -0.02em;
}
.hero-info .mark {
  width: 64px;
  height: auto;
  flex: none;
}
.hero-info .clip {
  background: var(--vp-home-hero-name-background);
  -webkit-background-clip: text;
  background-clip: text;
  -webkit-text-fill-color: var(--vp-home-hero-name-color);
}
.hero-info .tagline {
  margin: 0;
  max-width: 36rem;
  font-size: 18px;
  font-weight: 500;
  line-height: 1.5;
  color: var(--vp-c-text-2);
}
@media (max-width: 639px) {
  .hero-info .name {
    font-size: 36px;
    gap: 12px;
  }
  .hero-info .mark {
    width: 48px;
  }
}
</style>
