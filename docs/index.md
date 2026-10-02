---
layout: home

hero:
  name: TRITRI
  tagline: MAVLink dialect for Speed0 counter-UAS — MAVLink-M engagement plus lean C2 track messages.
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
  - title: Lean C2 track messages
    details: TRITRI_TRACK (53900) and TRITRI_TARGET (53901) are bandwidth-trimmed COP types for the LoRa C2 path — identity and kinematics correlated by track_uid.
  - title: Shared engagement vocabulary
    details: Handover, fires, directives, and BDA stay on the shared MAVLink-M IDs for interop.
  - title: Generated C headers
    details: CI publishes header-only C bindings to mavlink-tritri-c_library_v2 on every dialect change.
---
