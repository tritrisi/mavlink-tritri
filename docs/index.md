---
layout: home

hero:
  name: TRITRI
  tagline: MAVLink-M plus private COP messages for Speed0 counter-UAS command and control.
  actions:
    - theme: brand
      text: Introduction
      link: /en/index.md
    - theme: brand
      text: Messages
      link: /en/messages/tritri.md
    - theme: brand
      text: C2 Integration
      link: /C2_INTEGRATION.md
    - theme: alt
      text: Source (GitHub)
      link: https://github.com/tritrisi/mavlink-tritri

features:
  - title: Built on MAVLink-M
    details: Includes the shared MAVLink-M dialect and common.xml. Drops into any MAVLink 2 stack.
  - title: Private COP path
    details: TRITRI_TRACK and TRITRI_TARGET carry Speed0 live air picture over the reserved 53900–53999 block.
  - title: Shared engagement vocabulary
    details: Handover, fires, directives, and BDA stay on the shared MAVLink-M IDs for interop.
  - title: Generated C headers
    details: CI publishes header-only C bindings to mavlink-tritri-c_library_v2 on every dialect change.
---
