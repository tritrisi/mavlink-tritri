<script setup>
import { withBase } from "vitepress";
</script>

<template>
  <a class="hero-tritri" href="https://tritri.si" title="TRITRI">
    <img :src="withBase('/site/tritri_logo.png')" alt="TRITRI" width="96" height="89" />
  </a>
</template>

<style scoped>
.hero-tritri {
  display: inline-flex;
  align-items: center;
  margin-top: 32px;
  text-decoration: none;
}
.hero-tritri img {
  height: 72px;
  width: auto;
  object-fit: contain;
}
@media (max-width: 959px) {
  .hero-tritri {
    justify-content: center;
  }
}
</style>
